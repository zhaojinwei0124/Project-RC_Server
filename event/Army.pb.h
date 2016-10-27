// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef PROTOBUF_Army_2eproto__INCLUDED
#define PROTOBUF_Army_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Army_2eproto();
void protobuf_AssignDesc_Army_2eproto();
void protobuf_ShutdownFile_Army_2eproto();

class Army;

// ===================================================================

class Army : public ::google::protobuf::Message {
 public:
  Army();
  virtual ~Army();
  
  Army(const Army& from);
  
  inline Army& operator=(const Army& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Army& default_instance();
  void Swap(Army* other);
  
  // implements Message ----------------------------------------------
  
  Army* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Army& from);
  void MergeFrom(const Army& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional int32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);
  
  // optional int32 type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);
  
  // optional int32 X = 3;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 3;
  inline ::google::protobuf::int32 x() const;
  inline void set_x(::google::protobuf::int32 value);
  
  // optional int32 Y = 4;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 4;
  inline ::google::protobuf::int32 y() const;
  inline void set_y(::google::protobuf::int32 value);
  
  // optional int32 angle = 5;
  inline bool has_angle() const;
  inline void clear_angle();
  static const int kAngleFieldNumber = 5;
  inline ::google::protobuf::int32 angle() const;
  inline void set_angle(::google::protobuf::int32 value);
  
  // optional int32 health = 6;
  inline bool has_health() const;
  inline void clear_health();
  static const int kHealthFieldNumber = 6;
  inline ::google::protobuf::int32 health() const;
  inline void set_health(::google::protobuf::int32 value);
  
  // optional int32 stance = 7;
  inline bool has_stance() const;
  inline void clear_stance();
  static const int kStanceFieldNumber = 7;
  inline ::google::protobuf::int32 stance() const;
  inline void set_stance(::google::protobuf::int32 value);
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 x_;
  ::google::protobuf::int32 y_;
  ::google::protobuf::int32 angle_;
  ::google::protobuf::int32 health_;
  ::google::protobuf::int32 stance_;
  friend void  protobuf_AddDesc_Army_2eproto();
  friend void protobuf_AssignDesc_Army_2eproto();
  friend void protobuf_ShutdownFile_Army_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static Army* default_instance_;
};
// ===================================================================


// ===================================================================


// ===================================================================

// Army

// optional int32 id = 1;
inline bool Army::has_id() const {
  return _has_bit(0);
}
inline void Army::clear_id() {
  id_ = 0;
  _clear_bit(0);
}
inline ::google::protobuf::int32 Army::id() const {
  return id_;
}
inline void Army::set_id(::google::protobuf::int32 value) {
  _set_bit(0);
  id_ = value;
}

// optional int32 type = 2;
inline bool Army::has_type() const {
  return _has_bit(1);
}
inline void Army::clear_type() {
  type_ = 0;
  _clear_bit(1);
}
inline ::google::protobuf::int32 Army::type() const {
  return type_;
}
inline void Army::set_type(::google::protobuf::int32 value) {
  _set_bit(1);
  type_ = value;
}

// optional int32 X = 3;
inline bool Army::has_x() const {
  return _has_bit(2);
}
inline void Army::clear_x() {
  x_ = 0;
  _clear_bit(2);
}
inline ::google::protobuf::int32 Army::x() const {
  return x_;
}
inline void Army::set_x(::google::protobuf::int32 value) {
  _set_bit(2);
  x_ = value;
}

// optional int32 Y = 4;
inline bool Army::has_y() const {
  return _has_bit(3);
}
inline void Army::clear_y() {
  y_ = 0;
  _clear_bit(3);
}
inline ::google::protobuf::int32 Army::y() const {
  return y_;
}
inline void Army::set_y(::google::protobuf::int32 value) {
  _set_bit(3);
  y_ = value;
}

// optional int32 angle = 5;
inline bool Army::has_angle() const {
  return _has_bit(4);
}
inline void Army::clear_angle() {
  angle_ = 0;
  _clear_bit(4);
}
inline ::google::protobuf::int32 Army::angle() const {
  return angle_;
}
inline void Army::set_angle(::google::protobuf::int32 value) {
  _set_bit(4);
  angle_ = value;
}

// optional int32 health = 6;
inline bool Army::has_health() const {
  return _has_bit(5);
}
inline void Army::clear_health() {
  health_ = 0;
  _clear_bit(5);
}
inline ::google::protobuf::int32 Army::health() const {
  return health_;
}
inline void Army::set_health(::google::protobuf::int32 value) {
  _set_bit(5);
  health_ = value;
}

// optional int32 stance = 7;
inline bool Army::has_stance() const {
  return _has_bit(6);
}
inline void Army::clear_stance() {
  stance_ = 0;
  _clear_bit(6);
}
inline ::google::protobuf::int32 Army::stance() const {
  return stance_;
}
inline void Army::set_stance(::google::protobuf::int32 value) {
  _set_bit(6);
  stance_ = value;
}


#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

#endif  // PROTOBUF_Army_2eproto__INCLUDED
