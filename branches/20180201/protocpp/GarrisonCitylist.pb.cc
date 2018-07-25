// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GarrisonCitylist.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "GarrisonCitylist.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Hades {
namespace Data {

namespace {

const ::google::protobuf::Descriptor* GarrisonCitylist_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GarrisonCitylist_reflection_ = NULL;
const ::google::protobuf::Descriptor* MD5OfGarrisonCitylist_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MD5OfGarrisonCitylist_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_GarrisonCitylist_2eproto() {
  protobuf_AddDesc_GarrisonCitylist_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "GarrisonCitylist.proto");
  GOOGLE_CHECK(file != NULL);
  GarrisonCitylist_descriptor_ = file->message_type(0);
  static const int GarrisonCitylist_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, mapid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, area_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, fighting_enter_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, coin_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, exp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, item_),
  };
  GarrisonCitylist_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GarrisonCitylist_descriptor_,
      GarrisonCitylist::default_instance_,
      GarrisonCitylist_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GarrisonCitylist, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GarrisonCitylist));
  MD5OfGarrisonCitylist_descriptor_ = file->message_type(1);
  static const int MD5OfGarrisonCitylist_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MD5OfGarrisonCitylist, val_),
  };
  MD5OfGarrisonCitylist_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MD5OfGarrisonCitylist_descriptor_,
      MD5OfGarrisonCitylist::default_instance_,
      MD5OfGarrisonCitylist_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MD5OfGarrisonCitylist, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MD5OfGarrisonCitylist, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MD5OfGarrisonCitylist));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_GarrisonCitylist_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GarrisonCitylist_descriptor_, &GarrisonCitylist::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MD5OfGarrisonCitylist_descriptor_, &MD5OfGarrisonCitylist::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_GarrisonCitylist_2eproto() {
  delete GarrisonCitylist::default_instance_;
  delete GarrisonCitylist_reflection_;
  delete MD5OfGarrisonCitylist::default_instance_;
  delete MD5OfGarrisonCitylist_reflection_;
  delete MD5OfGarrisonCitylist::_default_val_;
}

void protobuf_AddDesc_GarrisonCitylist_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026GarrisonCitylist.proto\022\nHades.Data\"|\n\020"
    "GarrisonCitylist\022\n\n\002id\030\001 \001(\005\022\r\n\005mapid\030\002 "
    "\001(\005\022\014\n\004area\030\003 \001(\005\022\026\n\016fighting_enter\030\004 \001("
    "\005\022\014\n\004Coin\030\005 \001(\005\022\013\n\003Exp\030\006 \001(\005\022\014\n\004Item\030\007 \003"
    "(\005\"F\n\025MD5OfGarrisonCitylist\022-\n\003val\030\001 \001(\t"
    ": B47FAA3A55A419C164ECD428C8DE9F6A", 234);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "GarrisonCitylist.proto", &protobuf_RegisterTypes);
  GarrisonCitylist::default_instance_ = new GarrisonCitylist();
  MD5OfGarrisonCitylist::_default_val_ =
      new ::std::string("B47FAA3A55A419C164ECD428C8DE9F6A", 32);
  MD5OfGarrisonCitylist::default_instance_ = new MD5OfGarrisonCitylist();
  GarrisonCitylist::default_instance_->InitAsDefaultInstance();
  MD5OfGarrisonCitylist::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_GarrisonCitylist_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_GarrisonCitylist_2eproto {
  StaticDescriptorInitializer_GarrisonCitylist_2eproto() {
    protobuf_AddDesc_GarrisonCitylist_2eproto();
  }
} static_descriptor_initializer_GarrisonCitylist_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int GarrisonCitylist::kIdFieldNumber;
const int GarrisonCitylist::kMapidFieldNumber;
const int GarrisonCitylist::kAreaFieldNumber;
const int GarrisonCitylist::kFightingEnterFieldNumber;
const int GarrisonCitylist::kCoinFieldNumber;
const int GarrisonCitylist::kExpFieldNumber;
const int GarrisonCitylist::kItemFieldNumber;
#endif  // !_MSC_VER

GarrisonCitylist::GarrisonCitylist()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void GarrisonCitylist::InitAsDefaultInstance() {
}

GarrisonCitylist::GarrisonCitylist(const GarrisonCitylist& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void GarrisonCitylist::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  mapid_ = 0;
  area_ = 0;
  fighting_enter_ = 0;
  coin_ = 0;
  exp_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GarrisonCitylist::~GarrisonCitylist() {
  SharedDtor();
}

void GarrisonCitylist::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GarrisonCitylist::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GarrisonCitylist::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GarrisonCitylist_descriptor_;
}

const GarrisonCitylist& GarrisonCitylist::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_GarrisonCitylist_2eproto();
  return *default_instance_;
}

GarrisonCitylist* GarrisonCitylist::default_instance_ = NULL;

GarrisonCitylist* GarrisonCitylist::New() const {
  return new GarrisonCitylist;
}

void GarrisonCitylist::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    mapid_ = 0;
    area_ = 0;
    fighting_enter_ = 0;
    coin_ = 0;
    exp_ = 0;
  }
  item_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GarrisonCitylist::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_mapid;
        break;
      }

      // optional int32 mapid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_mapid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &mapid_)));
          set_has_mapid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_area;
        break;
      }

      // optional int32 area = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_area:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &area_)));
          set_has_area();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_fighting_enter;
        break;
      }

      // optional int32 fighting_enter = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fighting_enter:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &fighting_enter_)));
          set_has_fighting_enter();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_Coin;
        break;
      }

      // optional int32 Coin = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_Coin:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &coin_)));
          set_has_coin();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_Exp;
        break;
      }

      // optional int32 Exp = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_Exp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &exp_)));
          set_has_exp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_Item;
        break;
      }

      // repeated int32 Item = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_Item:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 56, input, this->mutable_item())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_item())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_Item;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void GarrisonCitylist::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional int32 mapid = 2;
  if (has_mapid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->mapid(), output);
  }

  // optional int32 area = 3;
  if (has_area()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->area(), output);
  }

  // optional int32 fighting_enter = 4;
  if (has_fighting_enter()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->fighting_enter(), output);
  }

  // optional int32 Coin = 5;
  if (has_coin()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->coin(), output);
  }

  // optional int32 Exp = 6;
  if (has_exp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->exp(), output);
  }

  // repeated int32 Item = 7;
  for (int i = 0; i < this->item_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      7, this->item(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* GarrisonCitylist::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional int32 mapid = 2;
  if (has_mapid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->mapid(), target);
  }

  // optional int32 area = 3;
  if (has_area()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->area(), target);
  }

  // optional int32 fighting_enter = 4;
  if (has_fighting_enter()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->fighting_enter(), target);
  }

  // optional int32 Coin = 5;
  if (has_coin()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->coin(), target);
  }

  // optional int32 Exp = 6;
  if (has_exp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->exp(), target);
  }

  // repeated int32 Item = 7;
  for (int i = 0; i < this->item_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(7, this->item(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int GarrisonCitylist::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional int32 mapid = 2;
    if (has_mapid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->mapid());
    }

    // optional int32 area = 3;
    if (has_area()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->area());
    }

    // optional int32 fighting_enter = 4;
    if (has_fighting_enter()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->fighting_enter());
    }

    // optional int32 Coin = 5;
    if (has_coin()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->coin());
    }

    // optional int32 Exp = 6;
    if (has_exp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->exp());
    }

  }
  // repeated int32 Item = 7;
  {
    int data_size = 0;
    for (int i = 0; i < this->item_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->item(i));
    }
    total_size += 1 * this->item_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GarrisonCitylist::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GarrisonCitylist* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GarrisonCitylist*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GarrisonCitylist::MergeFrom(const GarrisonCitylist& from) {
  GOOGLE_CHECK_NE(&from, this);
  item_.MergeFrom(from.item_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_mapid()) {
      set_mapid(from.mapid());
    }
    if (from.has_area()) {
      set_area(from.area());
    }
    if (from.has_fighting_enter()) {
      set_fighting_enter(from.fighting_enter());
    }
    if (from.has_coin()) {
      set_coin(from.coin());
    }
    if (from.has_exp()) {
      set_exp(from.exp());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GarrisonCitylist::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GarrisonCitylist::CopyFrom(const GarrisonCitylist& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GarrisonCitylist::IsInitialized() const {

  return true;
}

void GarrisonCitylist::Swap(GarrisonCitylist* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(mapid_, other->mapid_);
    std::swap(area_, other->area_);
    std::swap(fighting_enter_, other->fighting_enter_);
    std::swap(coin_, other->coin_);
    std::swap(exp_, other->exp_);
    item_.Swap(&other->item_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GarrisonCitylist::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GarrisonCitylist_descriptor_;
  metadata.reflection = GarrisonCitylist_reflection_;
  return metadata;
}


// ===================================================================

::std::string* MD5OfGarrisonCitylist::_default_val_ = NULL;
#ifndef _MSC_VER
const int MD5OfGarrisonCitylist::kValFieldNumber;
#endif  // !_MSC_VER

MD5OfGarrisonCitylist::MD5OfGarrisonCitylist()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MD5OfGarrisonCitylist::InitAsDefaultInstance() {
}

MD5OfGarrisonCitylist::MD5OfGarrisonCitylist(const MD5OfGarrisonCitylist& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MD5OfGarrisonCitylist::SharedCtor() {
  _cached_size_ = 0;
  val_ = const_cast< ::std::string*>(_default_val_);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MD5OfGarrisonCitylist::~MD5OfGarrisonCitylist() {
  SharedDtor();
}

void MD5OfGarrisonCitylist::SharedDtor() {
  if (val_ != _default_val_) {
    delete val_;
  }
  if (this != default_instance_) {
  }
}

void MD5OfGarrisonCitylist::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MD5OfGarrisonCitylist::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MD5OfGarrisonCitylist_descriptor_;
}

const MD5OfGarrisonCitylist& MD5OfGarrisonCitylist::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_GarrisonCitylist_2eproto();
  return *default_instance_;
}

MD5OfGarrisonCitylist* MD5OfGarrisonCitylist::default_instance_ = NULL;

MD5OfGarrisonCitylist* MD5OfGarrisonCitylist::New() const {
  return new MD5OfGarrisonCitylist;
}

void MD5OfGarrisonCitylist::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_val()) {
      if (val_ != _default_val_) {
        val_->assign(*_default_val_);
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MD5OfGarrisonCitylist::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string val = 1 [default = "B47FAA3A55A419C164ECD428C8DE9F6A"];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_val()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->val().data(), this->val().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MD5OfGarrisonCitylist::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional string val = 1 [default = "B47FAA3A55A419C164ECD428C8DE9F6A"];
  if (has_val()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->val().data(), this->val().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->val(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MD5OfGarrisonCitylist::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional string val = 1 [default = "B47FAA3A55A419C164ECD428C8DE9F6A"];
  if (has_val()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->val().data(), this->val().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->val(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MD5OfGarrisonCitylist::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string val = 1 [default = "B47FAA3A55A419C164ECD428C8DE9F6A"];
    if (has_val()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->val());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MD5OfGarrisonCitylist::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MD5OfGarrisonCitylist* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MD5OfGarrisonCitylist*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MD5OfGarrisonCitylist::MergeFrom(const MD5OfGarrisonCitylist& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_val()) {
      set_val(from.val());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MD5OfGarrisonCitylist::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MD5OfGarrisonCitylist::CopyFrom(const MD5OfGarrisonCitylist& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MD5OfGarrisonCitylist::IsInitialized() const {

  return true;
}

void MD5OfGarrisonCitylist::Swap(MD5OfGarrisonCitylist* other) {
  if (other != this) {
    std::swap(val_, other->val_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MD5OfGarrisonCitylist::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MD5OfGarrisonCitylist_descriptor_;
  metadata.reflection = MD5OfGarrisonCitylist_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Data
}  // namespace Hades

// @@protoc_insertion_point(global_scope)