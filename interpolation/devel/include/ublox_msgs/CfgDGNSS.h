// Generated by gencpp from file ublox_msgs/CfgDGNSS.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_CFGDGNSS_H
#define UBLOX_MSGS_MESSAGE_CFGDGNSS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ublox_msgs
{
template <class ContainerAllocator>
struct CfgDGNSS_
{
  typedef CfgDGNSS_<ContainerAllocator> Type;

  CfgDGNSS_()
    : dgnssMode(0)
    , reserved0()  {
      reserved0.assign(0);
  }
  CfgDGNSS_(const ContainerAllocator& _alloc)
    : dgnssMode(0)
    , reserved0()  {
  (void)_alloc;
      reserved0.assign(0);
  }



   typedef uint8_t _dgnssMode_type;
  _dgnssMode_type dgnssMode;

   typedef boost::array<uint8_t, 3>  _reserved0_type;
  _reserved0_type reserved0;



  enum {
    CLASS_ID = 6u,
    MESSAGE_ID = 112u,
    DGNSS_MODE_RTK_FLOAT = 2u,
    DGNSS_MODE_RTK_FIXED = 3u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> const> ConstPtr;

}; // struct CfgDGNSS_

typedef ::ublox_msgs::CfgDGNSS_<std::allocator<void> > CfgDGNSS;

typedef boost::shared_ptr< ::ublox_msgs::CfgDGNSS > CfgDGNSSPtr;
typedef boost::shared_ptr< ::ublox_msgs::CfgDGNSS const> CfgDGNSSConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::CfgDGNSS_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ublox_msgs': ['/home/young43/FOSCAR_ISCC_2021/src/gps/ublox/ublox_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2ec4391f93581f9db720bbc0af2b613e";
  }

  static const char* value(const ::ublox_msgs::CfgDGNSS_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2ec4391f93581f9dULL;
  static const uint64_t static_value2 = 0xb720bbc0af2b613eULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/CfgDGNSS";
  }

  static const char* value(const ::ublox_msgs::CfgDGNSS_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# CFG-DGNSS (0x06 0x70)\n\
# DGNSS configuration\n\
#\n\
# This message allows the user to configure the DGNSS configuration of the \n\
# receiver.\n\
# Supported on:\n\
#  - u-blox 8 / u-blox M8 from protocol version 20.01 up to version 23.01 (only\n\
#    with High Precision GNSS products)\n\
\n\
uint8 CLASS_ID = 6\n\
uint8 MESSAGE_ID = 112\n\
\n\
uint8 dgnssMode                 # Specifies differential mode:\n\
uint8 DGNSS_MODE_RTK_FLOAT = 2    # RTK float: No attempts are made to fix\n\
                                  # ambiguities.\n\
uint8 DGNSS_MODE_RTK_FIXED = 3    # RTK fixed: Ambiguities are fixed whenever\n\
                                  # possible.\n\
uint8[3] reserved0              # Reserved\n\
";
  }

  static const char* value(const ::ublox_msgs::CfgDGNSS_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dgnssMode);
      stream.next(m.reserved0);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CfgDGNSS_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::CfgDGNSS_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::CfgDGNSS_<ContainerAllocator>& v)
  {
    s << indent << "dgnssMode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.dgnssMode);
    s << indent << "reserved0[]" << std::endl;
    for (size_t i = 0; i < v.reserved0.size(); ++i)
    {
      s << indent << "  reserved0[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved0[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_CFGDGNSS_H