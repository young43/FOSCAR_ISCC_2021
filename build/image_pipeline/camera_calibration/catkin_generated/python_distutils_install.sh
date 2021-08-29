#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/foscar/ISCC_2021/src/image_pipeline/camera_calibration"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/foscar/ISCC_2021/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/foscar/ISCC_2021/install/lib/python2.7/dist-packages:/home/foscar/ISCC_2021/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/foscar/ISCC_2021/build" \
    "/usr/bin/python2" \
    "/home/foscar/ISCC_2021/src/image_pipeline/camera_calibration/setup.py" \
    egg_info --egg-base /home/foscar/ISCC_2021/build/image_pipeline/camera_calibration \
    build --build-base "/home/foscar/ISCC_2021/build/image_pipeline/camera_calibration" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/foscar/ISCC_2021/install" --install-scripts="/home/foscar/ISCC_2021/install/bin"
