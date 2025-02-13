// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: remotemap.proto

#include "remotemap.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_remotemap_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PBProductItem_remotemap_2eproto;
namespace remotemap {
class FloatDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Float> _instance;
} _Float_default_instance_;
class PBProductItemDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PBProductItem> _instance;
} _PBProductItem_default_instance_;
class PBShipmentInfoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PBShipmentInfo> _instance;
} _PBShipmentInfo_default_instance_;
}  // namespace remotemap
static void InitDefaultsscc_info_Float_remotemap_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::remotemap::_Float_default_instance_;
    new (ptr) ::remotemap::Float();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::remotemap::Float::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Float_remotemap_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Float_remotemap_2eproto}, {}};

static void InitDefaultsscc_info_PBProductItem_remotemap_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::remotemap::_PBProductItem_default_instance_;
    new (ptr) ::remotemap::PBProductItem();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::remotemap::PBProductItem::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PBProductItem_remotemap_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_PBProductItem_remotemap_2eproto}, {}};

static void InitDefaultsscc_info_PBShipmentInfo_remotemap_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::remotemap::_PBShipmentInfo_default_instance_;
    new (ptr) ::remotemap::PBShipmentInfo();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::remotemap::PBShipmentInfo::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_PBShipmentInfo_remotemap_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_PBShipmentInfo_remotemap_2eproto}, {
      &scc_info_PBProductItem_remotemap_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_remotemap_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_remotemap_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_remotemap_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_remotemap_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::remotemap::Float, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::remotemap::Float, result_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::remotemap::PBProductItem, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::remotemap::PBProductItem, price_),
  PROTOBUF_FIELD_OFFSET(::remotemap::PBProductItem, quantity_),
  PROTOBUF_FIELD_OFFSET(::remotemap::PBProductItem, discount_),
  PROTOBUF_FIELD_OFFSET(::remotemap::PBProductItem, packagingcost_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::remotemap::PBShipmentInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::remotemap::PBShipmentInfo, transportcost_),
  PROTOBUF_FIELD_OFFSET(::remotemap::PBShipmentInfo, stock_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::remotemap::Float)},
  { 6, -1, sizeof(::remotemap::PBProductItem)},
  { 15, -1, sizeof(::remotemap::PBShipmentInfo)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::remotemap::_Float_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::remotemap::_PBProductItem_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::remotemap::_PBShipmentInfo_default_instance_),
};

const char descriptor_table_protodef_remotemap_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017remotemap.proto\022\tremotemap\"\027\n\005Float\022\016\n"
  "\006result\030\001 \001(\002\"Y\n\rPBProductItem\022\r\n\005price\030"
  "\001 \001(\002\022\020\n\010quantity\030\002 \001(\002\022\020\n\010discount\030\003 \001("
  "\002\022\025\n\rpackagingCost\030\004 \001(\002\"P\n\016PBShipmentIn"
  "fo\022\025\n\rtransportCost\030\001 \001(\002\022\'\n\005stock\030\002 \003(\013"
  "2\030.remotemap.PBProductItem2I\n\016PBCalculat"
  "ions\0227\n\010calcCost\022\031.remotemap.PBShipmentI"
  "nfo\032\020.remotemap.FloatB\024\n\022com.logistics.G"
  "RPCb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_remotemap_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_remotemap_2eproto_sccs[3] = {
  &scc_info_Float_remotemap_2eproto.base,
  &scc_info_PBProductItem_remotemap_2eproto.base,
  &scc_info_PBShipmentInfo_remotemap_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_remotemap_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_remotemap_2eproto = {
  false, false, descriptor_table_protodef_remotemap_2eproto, "remotemap.proto", 331,
  &descriptor_table_remotemap_2eproto_once, descriptor_table_remotemap_2eproto_sccs, descriptor_table_remotemap_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_remotemap_2eproto::offsets,
  file_level_metadata_remotemap_2eproto, 3, file_level_enum_descriptors_remotemap_2eproto, file_level_service_descriptors_remotemap_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_remotemap_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_remotemap_2eproto)), true);
namespace remotemap {

// ===================================================================

void Float::InitAsDefaultInstance() {
}
class Float::_Internal {
 public:
};

Float::Float(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:remotemap.Float)
}
Float::Float(const Float& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  result_ = from.result_;
  // @@protoc_insertion_point(copy_constructor:remotemap.Float)
}

void Float::SharedCtor() {
  result_ = 0;
}

Float::~Float() {
  // @@protoc_insertion_point(destructor:remotemap.Float)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Float::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Float::ArenaDtor(void* object) {
  Float* _this = reinterpret_cast< Float* >(object);
  (void)_this;
}
void Float::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Float::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Float& Float::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Float_remotemap_2eproto.base);
  return *internal_default_instance();
}


void Float::Clear() {
// @@protoc_insertion_point(message_clear_start:remotemap.Float)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  result_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Float::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // float result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          result_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Float::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:remotemap.Float)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float result = 1;
  if (!(this->result() <= 0 && this->result() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_result(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:remotemap.Float)
  return target;
}

size_t Float::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:remotemap.Float)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float result = 1;
  if (!(this->result() <= 0 && this->result() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Float::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:remotemap.Float)
  GOOGLE_DCHECK_NE(&from, this);
  const Float* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Float>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:remotemap.Float)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:remotemap.Float)
    MergeFrom(*source);
  }
}

void Float::MergeFrom(const Float& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:remotemap.Float)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.result() <= 0 && from.result() >= 0)) {
    _internal_set_result(from._internal_result());
  }
}

void Float::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:remotemap.Float)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Float::CopyFrom(const Float& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:remotemap.Float)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Float::IsInitialized() const {
  return true;
}

void Float::InternalSwap(Float* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(result_, other->result_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Float::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void PBProductItem::InitAsDefaultInstance() {
}
class PBProductItem::_Internal {
 public:
};

PBProductItem::PBProductItem(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:remotemap.PBProductItem)
}
PBProductItem::PBProductItem(const PBProductItem& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&price_, &from.price_,
    static_cast<size_t>(reinterpret_cast<char*>(&packagingcost_) -
    reinterpret_cast<char*>(&price_)) + sizeof(packagingcost_));
  // @@protoc_insertion_point(copy_constructor:remotemap.PBProductItem)
}

void PBProductItem::SharedCtor() {
  ::memset(&price_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&packagingcost_) -
      reinterpret_cast<char*>(&price_)) + sizeof(packagingcost_));
}

PBProductItem::~PBProductItem() {
  // @@protoc_insertion_point(destructor:remotemap.PBProductItem)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PBProductItem::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void PBProductItem::ArenaDtor(void* object) {
  PBProductItem* _this = reinterpret_cast< PBProductItem* >(object);
  (void)_this;
}
void PBProductItem::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PBProductItem::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PBProductItem& PBProductItem::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PBProductItem_remotemap_2eproto.base);
  return *internal_default_instance();
}


void PBProductItem::Clear() {
// @@protoc_insertion_point(message_clear_start:remotemap.PBProductItem)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&price_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&packagingcost_) -
      reinterpret_cast<char*>(&price_)) + sizeof(packagingcost_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PBProductItem::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // float price = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          price_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float quantity = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          quantity_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float discount = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          discount_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float packagingCost = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37)) {
          packagingcost_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PBProductItem::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:remotemap.PBProductItem)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float price = 1;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_price(), target);
  }

  // float quantity = 2;
  if (!(this->quantity() <= 0 && this->quantity() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_quantity(), target);
  }

  // float discount = 3;
  if (!(this->discount() <= 0 && this->discount() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_discount(), target);
  }

  // float packagingCost = 4;
  if (!(this->packagingcost() <= 0 && this->packagingcost() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_packagingcost(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:remotemap.PBProductItem)
  return target;
}

size_t PBProductItem::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:remotemap.PBProductItem)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float price = 1;
  if (!(this->price() <= 0 && this->price() >= 0)) {
    total_size += 1 + 4;
  }

  // float quantity = 2;
  if (!(this->quantity() <= 0 && this->quantity() >= 0)) {
    total_size += 1 + 4;
  }

  // float discount = 3;
  if (!(this->discount() <= 0 && this->discount() >= 0)) {
    total_size += 1 + 4;
  }

  // float packagingCost = 4;
  if (!(this->packagingcost() <= 0 && this->packagingcost() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PBProductItem::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:remotemap.PBProductItem)
  GOOGLE_DCHECK_NE(&from, this);
  const PBProductItem* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PBProductItem>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:remotemap.PBProductItem)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:remotemap.PBProductItem)
    MergeFrom(*source);
  }
}

void PBProductItem::MergeFrom(const PBProductItem& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:remotemap.PBProductItem)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.price() <= 0 && from.price() >= 0)) {
    _internal_set_price(from._internal_price());
  }
  if (!(from.quantity() <= 0 && from.quantity() >= 0)) {
    _internal_set_quantity(from._internal_quantity());
  }
  if (!(from.discount() <= 0 && from.discount() >= 0)) {
    _internal_set_discount(from._internal_discount());
  }
  if (!(from.packagingcost() <= 0 && from.packagingcost() >= 0)) {
    _internal_set_packagingcost(from._internal_packagingcost());
  }
}

void PBProductItem::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:remotemap.PBProductItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PBProductItem::CopyFrom(const PBProductItem& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:remotemap.PBProductItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PBProductItem::IsInitialized() const {
  return true;
}

void PBProductItem::InternalSwap(PBProductItem* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PBProductItem, packagingcost_)
      + sizeof(PBProductItem::packagingcost_)
      - PROTOBUF_FIELD_OFFSET(PBProductItem, price_)>(
          reinterpret_cast<char*>(&price_),
          reinterpret_cast<char*>(&other->price_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PBProductItem::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void PBShipmentInfo::InitAsDefaultInstance() {
}
class PBShipmentInfo::_Internal {
 public:
};

PBShipmentInfo::PBShipmentInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  stock_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:remotemap.PBShipmentInfo)
}
PBShipmentInfo::PBShipmentInfo(const PBShipmentInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      stock_(from.stock_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  transportcost_ = from.transportcost_;
  // @@protoc_insertion_point(copy_constructor:remotemap.PBShipmentInfo)
}

void PBShipmentInfo::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_PBShipmentInfo_remotemap_2eproto.base);
  transportcost_ = 0;
}

PBShipmentInfo::~PBShipmentInfo() {
  // @@protoc_insertion_point(destructor:remotemap.PBShipmentInfo)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PBShipmentInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void PBShipmentInfo::ArenaDtor(void* object) {
  PBShipmentInfo* _this = reinterpret_cast< PBShipmentInfo* >(object);
  (void)_this;
}
void PBShipmentInfo::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PBShipmentInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PBShipmentInfo& PBShipmentInfo::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PBShipmentInfo_remotemap_2eproto.base);
  return *internal_default_instance();
}


void PBShipmentInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:remotemap.PBShipmentInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  stock_.Clear();
  transportcost_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PBShipmentInfo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // float transportCost = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          transportcost_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // repeated .remotemap.PBProductItem stock = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_stock(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PBShipmentInfo::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:remotemap.PBShipmentInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float transportCost = 1;
  if (!(this->transportcost() <= 0 && this->transportcost() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_transportcost(), target);
  }

  // repeated .remotemap.PBProductItem stock = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_stock_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_stock(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:remotemap.PBShipmentInfo)
  return target;
}

size_t PBShipmentInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:remotemap.PBShipmentInfo)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .remotemap.PBProductItem stock = 2;
  total_size += 1UL * this->_internal_stock_size();
  for (const auto& msg : this->stock_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // float transportCost = 1;
  if (!(this->transportcost() <= 0 && this->transportcost() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PBShipmentInfo::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:remotemap.PBShipmentInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const PBShipmentInfo* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PBShipmentInfo>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:remotemap.PBShipmentInfo)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:remotemap.PBShipmentInfo)
    MergeFrom(*source);
  }
}

void PBShipmentInfo::MergeFrom(const PBShipmentInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:remotemap.PBShipmentInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  stock_.MergeFrom(from.stock_);
  if (!(from.transportcost() <= 0 && from.transportcost() >= 0)) {
    _internal_set_transportcost(from._internal_transportcost());
  }
}

void PBShipmentInfo::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:remotemap.PBShipmentInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PBShipmentInfo::CopyFrom(const PBShipmentInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:remotemap.PBShipmentInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PBShipmentInfo::IsInitialized() const {
  return true;
}

void PBShipmentInfo::InternalSwap(PBShipmentInfo* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  stock_.InternalSwap(&other->stock_);
  swap(transportcost_, other->transportcost_);
}

::PROTOBUF_NAMESPACE_ID::Metadata PBShipmentInfo::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace remotemap
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::remotemap::Float* Arena::CreateMaybeMessage< ::remotemap::Float >(Arena* arena) {
  return Arena::CreateMessageInternal< ::remotemap::Float >(arena);
}
template<> PROTOBUF_NOINLINE ::remotemap::PBProductItem* Arena::CreateMaybeMessage< ::remotemap::PBProductItem >(Arena* arena) {
  return Arena::CreateMessageInternal< ::remotemap::PBProductItem >(arena);
}
template<> PROTOBUF_NOINLINE ::remotemap::PBShipmentInfo* Arena::CreateMaybeMessage< ::remotemap::PBShipmentInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::remotemap::PBShipmentInfo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
