// Generated by gencpp from file rdl/jangs.msg
// DO NOT EDIT!


#ifndef RDL_MESSAGE_JANGS_H
#define RDL_MESSAGE_JANGS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rdl
{
template <class ContainerAllocator>
struct jangs_
{
  typedef jangs_<ContainerAllocator> Type;

  jangs_()
    : q()  {
      q.assign(0.0);
  }
  jangs_(const ContainerAllocator& _alloc)
    : q()  {
  (void)_alloc;
      q.assign(0.0);
  }



   typedef boost::array<float, 5>  _q_type;
  _q_type q;





  typedef boost::shared_ptr< ::rdl::jangs_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rdl::jangs_<ContainerAllocator> const> ConstPtr;

}; // struct jangs_

typedef ::rdl::jangs_<std::allocator<void> > jangs;

typedef boost::shared_ptr< ::rdl::jangs > jangsPtr;
typedef boost::shared_ptr< ::rdl::jangs const> jangsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rdl::jangs_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rdl::jangs_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rdl

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'rdl': ['/home/chenshengchen/New_lamp_control/rdl_ws/src/rdl/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rdl::jangs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rdl::jangs_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rdl::jangs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rdl::jangs_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rdl::jangs_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rdl::jangs_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rdl::jangs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d7d622de160bc058ec8b0b47fd78e313";
  }

  static const char* value(const ::rdl::jangs_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd7d622de160bc058ULL;
  static const uint64_t static_value2 = 0xec8b0b47fd78e313ULL;
};

template<class ContainerAllocator>
struct DataType< ::rdl::jangs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rdl/jangs";
  }

  static const char* value(const ::rdl::jangs_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rdl::jangs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[5] q\n\
";
  }

  static const char* value(const ::rdl::jangs_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rdl::jangs_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.q);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct jangs_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rdl::jangs_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rdl::jangs_<ContainerAllocator>& v)
  {
    s << indent << "q[]" << std::endl;
    for (size_t i = 0; i < v.q.size(); ++i)
    {
      s << indent << "  q[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.q[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // RDL_MESSAGE_JANGS_H
