// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: remotemap.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_remotemap_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_remotemap_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_remotemap_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_remotemap_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_remotemap_2eproto;
namespace remotemap {
class Float;
class FloatDefaultTypeInternal;
extern FloatDefaultTypeInternal _Float_default_instance_;
class PBProductItem;
class PBProductItemDefaultTypeInternal;
extern PBProductItemDefaultTypeInternal _PBProductItem_default_instance_;
class PBShipmentInfo;
class PBShipmentInfoDefaultTypeInternal;
extern PBShipmentInfoDefaultTypeInternal _PBShipmentInfo_default_instance_;
}  // namespace remotemap
PROTOBUF_NAMESPACE_OPEN
template<> ::remotemap::Float* Arena::CreateMaybeMessage<::remotemap::Float>(Arena*);
template<> ::remotemap::PBProductItem* Arena::CreateMaybeMessage<::remotemap::PBProductItem>(Arena*);
template<> ::remotemap::PBShipmentInfo* Arena::CreateMaybeMessage<::remotemap::PBShipmentInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace remotemap {

// ===================================================================

class Float PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:remotemap.Float) */ {
 public:
  inline Float() : Float(nullptr) {};
  virtual ~Float();

  Float(const Float& from);
  Float(Float&& from) noexcept
    : Float() {
    *this = ::std::move(from);
  }

  inline Float& operator=(const Float& from) {
    CopyFrom(from);
    return *this;
  }
  inline Float& operator=(Float&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Float& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Float* internal_default_instance() {
    return reinterpret_cast<const Float*>(
               &_Float_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Float& a, Float& b) {
    a.Swap(&b);
  }
  inline void Swap(Float* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Float* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Float* New() const final {
    return CreateMaybeMessage<Float>(nullptr);
  }

  Float* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Float>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Float& from);
  void MergeFrom(const Float& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Float* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "remotemap.Float";
  }
  protected:
  explicit Float(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_remotemap_2eproto);
    return ::descriptor_table_remotemap_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kResultFieldNumber = 1,
  };
  // float result = 1;
  void clear_result();
  float result() const;
  void set_result(float value);
  private:
  float _internal_result() const;
  void _internal_set_result(float value);
  public:

  // @@protoc_insertion_point(class_scope:remotemap.Float)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  float result_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_remotemap_2eproto;
};
// -------------------------------------------------------------------

class PBProductItem PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:remotemap.PBProductItem) */ {
 public:
  inline PBProductItem() : PBProductItem(nullptr) {};
  virtual ~PBProductItem();

  PBProductItem(const PBProductItem& from);
  PBProductItem(PBProductItem&& from) noexcept
    : PBProductItem() {
    *this = ::std::move(from);
  }

  inline PBProductItem& operator=(const PBProductItem& from) {
    CopyFrom(from);
    return *this;
  }
  inline PBProductItem& operator=(PBProductItem&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const PBProductItem& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PBProductItem* internal_default_instance() {
    return reinterpret_cast<const PBProductItem*>(
               &_PBProductItem_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PBProductItem& a, PBProductItem& b) {
    a.Swap(&b);
  }
  inline void Swap(PBProductItem* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PBProductItem* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PBProductItem* New() const final {
    return CreateMaybeMessage<PBProductItem>(nullptr);
  }

  PBProductItem* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PBProductItem>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PBProductItem& from);
  void MergeFrom(const PBProductItem& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PBProductItem* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "remotemap.PBProductItem";
  }
  protected:
  explicit PBProductItem(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_remotemap_2eproto);
    return ::descriptor_table_remotemap_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPriceFieldNumber = 1,
    kQuantityFieldNumber = 2,
    kDiscountFieldNumber = 3,
    kPackagingCostFieldNumber = 4,
  };
  // float price = 1;
  void clear_price();
  float price() const;
  void set_price(float value);
  private:
  float _internal_price() const;
  void _internal_set_price(float value);
  public:

  // float quantity = 2;
  void clear_quantity();
  float quantity() const;
  void set_quantity(float value);
  private:
  float _internal_quantity() const;
  void _internal_set_quantity(float value);
  public:

  // float discount = 3;
  void clear_discount();
  float discount() const;
  void set_discount(float value);
  private:
  float _internal_discount() const;
  void _internal_set_discount(float value);
  public:

  // float packagingCost = 4;
  void clear_packagingcost();
  float packagingcost() const;
  void set_packagingcost(float value);
  private:
  float _internal_packagingcost() const;
  void _internal_set_packagingcost(float value);
  public:

  // @@protoc_insertion_point(class_scope:remotemap.PBProductItem)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  float price_;
  float quantity_;
  float discount_;
  float packagingcost_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_remotemap_2eproto;
};
// -------------------------------------------------------------------

class PBShipmentInfo PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:remotemap.PBShipmentInfo) */ {
 public:
  inline PBShipmentInfo() : PBShipmentInfo(nullptr) {};
  virtual ~PBShipmentInfo();

  PBShipmentInfo(const PBShipmentInfo& from);
  PBShipmentInfo(PBShipmentInfo&& from) noexcept
    : PBShipmentInfo() {
    *this = ::std::move(from);
  }

  inline PBShipmentInfo& operator=(const PBShipmentInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline PBShipmentInfo& operator=(PBShipmentInfo&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const PBShipmentInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PBShipmentInfo* internal_default_instance() {
    return reinterpret_cast<const PBShipmentInfo*>(
               &_PBShipmentInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(PBShipmentInfo& a, PBShipmentInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(PBShipmentInfo* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PBShipmentInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PBShipmentInfo* New() const final {
    return CreateMaybeMessage<PBShipmentInfo>(nullptr);
  }

  PBShipmentInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PBShipmentInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PBShipmentInfo& from);
  void MergeFrom(const PBShipmentInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PBShipmentInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "remotemap.PBShipmentInfo";
  }
  protected:
  explicit PBShipmentInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_remotemap_2eproto);
    return ::descriptor_table_remotemap_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStockFieldNumber = 2,
    kTransportCostFieldNumber = 1,
  };
  // repeated .remotemap.PBProductItem stock = 2;
  int stock_size() const;
  private:
  int _internal_stock_size() const;
  public:
  void clear_stock();
  ::remotemap::PBProductItem* mutable_stock(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::remotemap::PBProductItem >*
      mutable_stock();
  private:
  const ::remotemap::PBProductItem& _internal_stock(int index) const;
  ::remotemap::PBProductItem* _internal_add_stock();
  public:
  const ::remotemap::PBProductItem& stock(int index) const;
  ::remotemap::PBProductItem* add_stock();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::remotemap::PBProductItem >&
      stock() const;

  // float transportCost = 1;
  void clear_transportcost();
  float transportcost() const;
  void set_transportcost(float value);
  private:
  float _internal_transportcost() const;
  void _internal_set_transportcost(float value);
  public:

  // @@protoc_insertion_point(class_scope:remotemap.PBShipmentInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::remotemap::PBProductItem > stock_;
  float transportcost_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_remotemap_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Float

// float result = 1;
inline void Float::clear_result() {
  result_ = 0;
}
inline float Float::_internal_result() const {
  return result_;
}
inline float Float::result() const {
  // @@protoc_insertion_point(field_get:remotemap.Float.result)
  return _internal_result();
}
inline void Float::_internal_set_result(float value) {
  
  result_ = value;
}
inline void Float::set_result(float value) {
  _internal_set_result(value);
  // @@protoc_insertion_point(field_set:remotemap.Float.result)
}

// -------------------------------------------------------------------

// PBProductItem

// float price = 1;
inline void PBProductItem::clear_price() {
  price_ = 0;
}
inline float PBProductItem::_internal_price() const {
  return price_;
}
inline float PBProductItem::price() const {
  // @@protoc_insertion_point(field_get:remotemap.PBProductItem.price)
  return _internal_price();
}
inline void PBProductItem::_internal_set_price(float value) {
  
  price_ = value;
}
inline void PBProductItem::set_price(float value) {
  _internal_set_price(value);
  // @@protoc_insertion_point(field_set:remotemap.PBProductItem.price)
}

// float quantity = 2;
inline void PBProductItem::clear_quantity() {
  quantity_ = 0;
}
inline float PBProductItem::_internal_quantity() const {
  return quantity_;
}
inline float PBProductItem::quantity() const {
  // @@protoc_insertion_point(field_get:remotemap.PBProductItem.quantity)
  return _internal_quantity();
}
inline void PBProductItem::_internal_set_quantity(float value) {
  
  quantity_ = value;
}
inline void PBProductItem::set_quantity(float value) {
  _internal_set_quantity(value);
  // @@protoc_insertion_point(field_set:remotemap.PBProductItem.quantity)
}

// float discount = 3;
inline void PBProductItem::clear_discount() {
  discount_ = 0;
}
inline float PBProductItem::_internal_discount() const {
  return discount_;
}
inline float PBProductItem::discount() const {
  // @@protoc_insertion_point(field_get:remotemap.PBProductItem.discount)
  return _internal_discount();
}
inline void PBProductItem::_internal_set_discount(float value) {
  
  discount_ = value;
}
inline void PBProductItem::set_discount(float value) {
  _internal_set_discount(value);
  // @@protoc_insertion_point(field_set:remotemap.PBProductItem.discount)
}

// float packagingCost = 4;
inline void PBProductItem::clear_packagingcost() {
  packagingcost_ = 0;
}
inline float PBProductItem::_internal_packagingcost() const {
  return packagingcost_;
}
inline float PBProductItem::packagingcost() const {
  // @@protoc_insertion_point(field_get:remotemap.PBProductItem.packagingCost)
  return _internal_packagingcost();
}
inline void PBProductItem::_internal_set_packagingcost(float value) {
  
  packagingcost_ = value;
}
inline void PBProductItem::set_packagingcost(float value) {
  _internal_set_packagingcost(value);
  // @@protoc_insertion_point(field_set:remotemap.PBProductItem.packagingCost)
}

// -------------------------------------------------------------------

// PBShipmentInfo

// float transportCost = 1;
inline void PBShipmentInfo::clear_transportcost() {
  transportcost_ = 0;
}
inline float PBShipmentInfo::_internal_transportcost() const {
  return transportcost_;
}
inline float PBShipmentInfo::transportcost() const {
  // @@protoc_insertion_point(field_get:remotemap.PBShipmentInfo.transportCost)
  return _internal_transportcost();
}
inline void PBShipmentInfo::_internal_set_transportcost(float value) {
  
  transportcost_ = value;
}
inline void PBShipmentInfo::set_transportcost(float value) {
  _internal_set_transportcost(value);
  // @@protoc_insertion_point(field_set:remotemap.PBShipmentInfo.transportCost)
}

// repeated .remotemap.PBProductItem stock = 2;
inline int PBShipmentInfo::_internal_stock_size() const {
  return stock_.size();
}
inline int PBShipmentInfo::stock_size() const {
  return _internal_stock_size();
}
inline void PBShipmentInfo::clear_stock() {
  stock_.Clear();
}
inline ::remotemap::PBProductItem* PBShipmentInfo::mutable_stock(int index) {
  // @@protoc_insertion_point(field_mutable:remotemap.PBShipmentInfo.stock)
  return stock_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::remotemap::PBProductItem >*
PBShipmentInfo::mutable_stock() {
  // @@protoc_insertion_point(field_mutable_list:remotemap.PBShipmentInfo.stock)
  return &stock_;
}
inline const ::remotemap::PBProductItem& PBShipmentInfo::_internal_stock(int index) const {
  return stock_.Get(index);
}
inline const ::remotemap::PBProductItem& PBShipmentInfo::stock(int index) const {
  // @@protoc_insertion_point(field_get:remotemap.PBShipmentInfo.stock)
  return _internal_stock(index);
}
inline ::remotemap::PBProductItem* PBShipmentInfo::_internal_add_stock() {
  return stock_.Add();
}
inline ::remotemap::PBProductItem* PBShipmentInfo::add_stock() {
  // @@protoc_insertion_point(field_add:remotemap.PBShipmentInfo.stock)
  return _internal_add_stock();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::remotemap::PBProductItem >&
PBShipmentInfo::stock() const {
  // @@protoc_insertion_point(field_list:remotemap.PBShipmentInfo.stock)
  return stock_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace remotemap

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_remotemap_2eproto
