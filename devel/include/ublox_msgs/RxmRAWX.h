// Generated by gencpp from file ublox_msgs/RxmRAWX.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_RXMRAWX_H
#define UBLOX_MSGS_MESSAGE_RXMRAWX_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ublox_msgs/RxmRAWX_Meas.h>

namespace ublox_msgs
{
template <class ContainerAllocator>
struct RxmRAWX_
{
  typedef RxmRAWX_<ContainerAllocator> Type;

  RxmRAWX_()
    : rcvTOW(0.0)
    , week(0)
    , leapS(0)
    , numMeas(0)
    , recStat(0)
    , version(0)
    , reserved1()
    , meas()  {
      reserved1.assign(0);
  }
  RxmRAWX_(const ContainerAllocator& _alloc)
    : rcvTOW(0.0)
    , week(0)
    , leapS(0)
    , numMeas(0)
    , recStat(0)
    , version(0)
    , reserved1()
    , meas(_alloc)  {
  (void)_alloc;
      reserved1.assign(0);
  }



   typedef double _rcvTOW_type;
  _rcvTOW_type rcvTOW;

   typedef uint16_t _week_type;
  _week_type week;

   typedef int8_t _leapS_type;
  _leapS_type leapS;

   typedef uint8_t _numMeas_type;
  _numMeas_type numMeas;

   typedef uint8_t _recStat_type;
  _recStat_type recStat;

   typedef uint8_t _version_type;
  _version_type version;

   typedef boost::array<uint8_t, 2>  _reserved1_type;
  _reserved1_type reserved1;

   typedef std::vector< ::ublox_msgs::RxmRAWX_Meas_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ublox_msgs::RxmRAWX_Meas_<ContainerAllocator> >::other >  _meas_type;
  _meas_type meas;



  enum {
    CLASS_ID = 2u,
    MESSAGE_ID = 21u,
    REC_STAT_LEAP_SEC = 1u,
    REC_STAT_CLK_RESET = 2u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::RxmRAWX_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::RxmRAWX_<ContainerAllocator> const> ConstPtr;

}; // struct RxmRAWX_

typedef ::ublox_msgs::RxmRAWX_<std::allocator<void> > RxmRAWX;

typedef boost::shared_ptr< ::ublox_msgs::RxmRAWX > RxmRAWXPtr;
typedef boost::shared_ptr< ::ublox_msgs::RxmRAWX const> RxmRAWXConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::RxmRAWX_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ublox_msgs': ['/home/young43/FOSCAR_ISCC_2021/src/gps/ublox/ublox_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmRAWX_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmRAWX_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmRAWX_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a2df4b27b6a2a1565e42f5669dbb11b5";
  }

  static const char* value(const ::ublox_msgs::RxmRAWX_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa2df4b27b6a2a156ULL;
  static const uint64_t static_value2 = 0x5e42f5669dbb11b5ULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/RxmRAWX";
  }

  static const char* value(const ::ublox_msgs::RxmRAWX_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# RXM-RAWX (0x02 0x15)\n\
# Multi-GNSS Raw Measurement Data\n\
#\n\
# This message contains the information needed to be able to generate a RINEX 3\n\
# multi-GNSS observation file.\n\
# This message contains pseudorange, Doppler, carrier phase, phase lock and\n\
# signal quality information for GNSS satellites once signals have been\n\
# synchronized. This message supports all active GNSS.\n\
# \n\
\n\
uint8 CLASS_ID = 2\n\
uint8 MESSAGE_ID = 21\n\
\n\
float64 rcvTOW          # Measurement time of week in receiver local time [s]\n\
                        # approximately aligned to the GPS time system. The\n\
                        # receiver local time of week number and leap second\n\
                        # information can be used to translate the time to other \n\
                        # time systems. More information about the difference in\n\
                        # time systems can be found in RINEX 3 documentation. \n\
                        # For a receiver operating in GLONASS only mode, UTC\n\
                        # time can be determined by subtracting the leapS field \n\
                        # from GPS time regardless of whether the GPS leap\n\
                        # seconds are valid. \n\
uint16 week             # GPS week number in receiver local time. [weeks]\n\
int8 leapS              # GPS leap seconds (GPS-UTC). [s]\n\
                        # This field represents the receiver's best knowledge of\n\
                        # the leap seconds offset. A flag is given in the\n\
                        # recStat bitfield to indicate if the leap seconds \n\
                        # are known.\n\
uint8 numMeas           # # of measurements to follow\n\
uint8 recStat           # Receiver tracking status bitfield\n\
uint8 REC_STAT_LEAP_SEC = 1   # Leap seconds have been determined\n\
uint8 REC_STAT_CLK_RESET = 2  # Clock reset applied. Typically the receiver  \n\
                              # clock is changed in increments of integer\n\
                              # milliseconds.\n\
uint8 version           # Message version (0x01 for this version).\n\
uint8[2] reserved1      # Reserved\n\
\n\
RxmRAWX_Meas[] meas\n\
\n\
================================================================================\n\
MSG: ublox_msgs/RxmRAWX_Meas\n\
# see message RxmRAWX\n\
#\n\
\n\
float64 prMes             # Pseudorange measurement [m]. GLONASS inter frequency\n\
                          # channel delays are compensated with an internal\n\
                          # calibration table.\n\
float64 cpMes             # Carrier phase measurement [L1 cycles]. The carrier\n\
                          # phase initial ambiguity is initialized using an\n\
                          # approximate value to make the magnitude of\n\
                          # the phase close to the pseudorange\n\
                          # measurement. Clock resets are applied to both\n\
                          # phase and code measurements in accordance\n\
                          # with the RINEX specification.\n\
float32 doMes             # Doppler measurement [Hz] (positive sign for\n\
                          # approaching satellites)\n\
uint8 gnssId              # GNSS identifier (see CfgGNSS for constants)\n\
\n\
uint8 svId                # Satellite identifier (see Satellite Numbering)\n\
\n\
uint8 reserved0           # Reserved\n\
\n\
uint8 freqId              # Only used for GLONASS: This is the frequency\n\
                          # slot + 7 (range from 0 to 13)\n\
uint16 locktime           # Carrier phase locktime counter [ms] \n\
                          # (maximum 64500 ms)\n\
int8 cno                  # Carrier-to-noise density ratio (signal strength) \n\
                          # [dB-Hz]\n\
uint8 prStdev             # Estimated pseudorange measurement standard\n\
                          # deviation [m / 0.01*2^n]\n\
uint8 cpStdev             # Estimated carrier phase measurement standard\n\
                          # deviation (note a raw value of 0x0F indicates the\n\
                          # value is invalid) [cycles / 0.004]\n\
uint8 doStdev             # Estimated Doppler measurement standard deviation \n\
                          # [Hz / 0.002*2^n]\n\
\n\
uint8 trkStat             # Tracking status bitfield\n\
uint8 TRK_STAT_PR_VALID = 1       # Pseudorange valid\n\
uint8 TRK_STAT_CP_VALID = 2       # Carrier phase valid\n\
uint8 TRK_STAT_HALF_CYC = 4       # Half cycle valid\n\
uint8 TRK_STAT_SUB_HALF_CYC = 8   # Half cycle subtracted from phase\n\
\n\
uint8 reserved1           # Reserved\n\
";
  }

  static const char* value(const ::ublox_msgs::RxmRAWX_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.rcvTOW);
      stream.next(m.week);
      stream.next(m.leapS);
      stream.next(m.numMeas);
      stream.next(m.recStat);
      stream.next(m.version);
      stream.next(m.reserved1);
      stream.next(m.meas);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RxmRAWX_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::RxmRAWX_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::RxmRAWX_<ContainerAllocator>& v)
  {
    s << indent << "rcvTOW: ";
    Printer<double>::stream(s, indent + "  ", v.rcvTOW);
    s << indent << "week: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.week);
    s << indent << "leapS: ";
    Printer<int8_t>::stream(s, indent + "  ", v.leapS);
    s << indent << "numMeas: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.numMeas);
    s << indent << "recStat: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.recStat);
    s << indent << "version: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.version);
    s << indent << "reserved1[]" << std::endl;
    for (size_t i = 0; i < v.reserved1.size(); ++i)
    {
      s << indent << "  reserved1[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved1[i]);
    }
    s << indent << "meas[]" << std::endl;
    for (size_t i = 0; i < v.meas.size(); ++i)
    {
      s << indent << "  meas[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ublox_msgs::RxmRAWX_Meas_<ContainerAllocator> >::stream(s, indent + "    ", v.meas[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_RXMRAWX_H
