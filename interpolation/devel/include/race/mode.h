// Generated by gencpp from file race/mode.msg
// DO NOT EDIT!


#ifndef RACE_MESSAGE_MODE_H
#define RACE_MESSAGE_MODE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace race
{
template <class ContainerAllocator>
struct mode_
{
  typedef mode_<ContainerAllocator> Type;

  mode_()
    : status(0)
    , mode(0)
    , spd_limit(0)  {
    }
  mode_(const ContainerAllocator& _alloc)
    : status(0)
    , mode(0)
    , spd_limit(0)  {
  (void)_alloc;
    }



   typedef int8_t _status_type;
  _status_type status;

   typedef int8_t _mode_type;
  _mode_type mode;

   typedef int8_t _spd_limit_type;
  _spd_limit_type spd_limit;





  typedef boost::shared_ptr< ::race::mode_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::race::mode_<ContainerAllocator> const> ConstPtr;

}; // struct mode_

typedef ::race::mode_<std::allocator<void> > mode;

typedef boost::shared_ptr< ::race::mode > modePtr;
typedef boost::shared_ptr< ::race::mode const> modeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::race::mode_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::race::mode_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace race

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'race': ['/home/young43/FOSCAR_ISCC_2021/src/race/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::race::mode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::race::mode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::race::mode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::race::mode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::race::mode_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::race::mode_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::race::mode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4d86579415141bf5b868c51e2a521f14";
  }

  static const char* value(const ::race::mode_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4d86579415141bf5ULL;
  static const uint64_t static_value2 = 0xb868c51e2a521f14ULL;
};

template<class ContainerAllocator>
struct DataType< ::race::mode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "race/mode";
  }

  static const char* value(const ::race::mode_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::race::mode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 status\n\
int8 mode\n\
int8 spd_limit\n\
";
  }

  static const char* value(const ::race::mode_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::race::mode_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
      stream.next(m.mode);
      stream.next(m.spd_limit);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct mode_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::race::mode_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::race::mode_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<int8_t>::stream(s, indent + "  ", v.status);
    s << indent << "mode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.mode);
    s << indent << "spd_limit: ";
    Printer<int8_t>::stream(s, indent + "  ", v.spd_limit);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RACE_MESSAGE_MODE_H