# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ublox_msgs/NavSVINFO_SV.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class NavSVINFO_SV(genpy.Message):
  _md5sum = "fd3d8150f431e87f504da9aafff163a1"
  _type = "ublox_msgs/NavSVINFO_SV"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """# see message NavSVINFO
#

uint8 chn             # Channel number, 255 for SVs not assigned to a channel
uint8 svid            # Satellite ID

uint8 flags           # Bitmask
uint8 FLAGS_SV_USED = 1                     # SV is used for navigation
uint8 FLAGS_DIFF_CORR = 2                   # Differential correction data 
                                            # is available for this SV
uint8 FLAGS_ORBIT_AVAIL = 4                 # Orbit information is available for 
                                            # this SV (Ephemeris or Almanach)
uint8 FLAGS_ORBIT_EPH = 8                   # Orbit information is Ephemeris
uint8 FLAGS_UNHEALTHY = 16                  # SV is unhealthy / shall not be 
                                            # used
uint8 FLAGS_ORBIT_ALM = 32                  # Orbit information is Almanac Plus
uint8 FLAGS_ORBIT_AOP = 64                  # Orbit information is AssistNow 
                                            # Autonomous
uint8 FLAGS_SMOOTHED = 128                  # Carrier smoothed pseudorange used

uint8 quality         # Bitfield
# qualityInd: Signal Quality indicator (range 0..7). The following list shows 
# the meaning of the different QI values:
# Note: Since IMES signals are not time synchronized, a channel tracking an IMES
# signal can never reach a quality indicator value of higher than 3.
uint8 QUALITY_IDLE = 0                      # This channel is idle
uint8 QUALITY_SEARCHING = 1                 # Channel is searching
uint8 QUALITY_ACQUIRED = 2                   # Signal acquired
uint8 QUALITY_DETECTED = 3                  # Signal detected but unusable
uint8 QUALITY_CODE_LOCK = 4                 # Code Lock on Signal
uint8 QUALITY_CODE_AND_CARRIER_LOCKED1 = 5  # Code and Carrier locked 
                                            # and time synchronized
uint8 QUALITY_CODE_AND_CARRIER_LOCKED2 = 6  # Code and Carrier locked 
                                            # and time synchronized
uint8 QUALITY_CODE_AND_CARRIER_LOCKED3 = 7  # Code and Carrier locked 
                                            # and time synchronized

uint8 cno             # Carrier to Noise Ratio (Signal Strength) [dBHz]
int8 elev             # Elevation in integer degrees [deg]
int16 azim            # Azimuth in integer degrees [deg]
int32 prRes           # Pseudo range residual in centimetres [cm]
"""
  # Pseudo-constants
  FLAGS_SV_USED = 1
  FLAGS_DIFF_CORR = 2
  FLAGS_ORBIT_AVAIL = 4
  FLAGS_ORBIT_EPH = 8
  FLAGS_UNHEALTHY = 16
  FLAGS_ORBIT_ALM = 32
  FLAGS_ORBIT_AOP = 64
  FLAGS_SMOOTHED = 128
  QUALITY_IDLE = 0
  QUALITY_SEARCHING = 1
  QUALITY_ACQUIRED = 2
  QUALITY_DETECTED = 3
  QUALITY_CODE_LOCK = 4
  QUALITY_CODE_AND_CARRIER_LOCKED1 = 5
  QUALITY_CODE_AND_CARRIER_LOCKED2 = 6
  QUALITY_CODE_AND_CARRIER_LOCKED3 = 7

  __slots__ = ['chn','svid','flags','quality','cno','elev','azim','prRes']
  _slot_types = ['uint8','uint8','uint8','uint8','uint8','int8','int16','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       chn,svid,flags,quality,cno,elev,azim,prRes

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(NavSVINFO_SV, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.chn is None:
        self.chn = 0
      if self.svid is None:
        self.svid = 0
      if self.flags is None:
        self.flags = 0
      if self.quality is None:
        self.quality = 0
      if self.cno is None:
        self.cno = 0
      if self.elev is None:
        self.elev = 0
      if self.azim is None:
        self.azim = 0
      if self.prRes is None:
        self.prRes = 0
    else:
      self.chn = 0
      self.svid = 0
      self.flags = 0
      self.quality = 0
      self.cno = 0
      self.elev = 0
      self.azim = 0
      self.prRes = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_5Bbhi().pack(_x.chn, _x.svid, _x.flags, _x.quality, _x.cno, _x.elev, _x.azim, _x.prRes))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 12
      (_x.chn, _x.svid, _x.flags, _x.quality, _x.cno, _x.elev, _x.azim, _x.prRes,) = _get_struct_5Bbhi().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_5Bbhi().pack(_x.chn, _x.svid, _x.flags, _x.quality, _x.cno, _x.elev, _x.azim, _x.prRes))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 12
      (_x.chn, _x.svid, _x.flags, _x.quality, _x.cno, _x.elev, _x.azim, _x.prRes,) = _get_struct_5Bbhi().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_5Bbhi = None
def _get_struct_5Bbhi():
    global _struct_5Bbhi
    if _struct_5Bbhi is None:
        _struct_5Bbhi = struct.Struct("<5Bbhi")
    return _struct_5Bbhi
