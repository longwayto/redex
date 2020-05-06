/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "FrequentlyUsedPointersCache.h"

#include "DexClass.h"

#define DEFINE_FREQUENTLY_USED_TYPE(func_name, java_name) \
  DexType* FrequentlyUsedPointers::type_##func_name() {   \
    if (!m_type_##func_name) {                            \
      m_type_##func_name = DexType::make_type(java_name); \
    }                                                     \
    return m_type_##func_name;                            \
  }

#define DEFINE_FREQUENTLY_USED_FIELD(func_name, java_name)   \
  DexFieldRef* FrequentlyUsedPointers::field_##func_name() { \
    if (!m_field_##func_name) {                              \
      m_field_##func_name = DexField::make_field(java_name); \
    }                                                        \
    return m_field_##func_name;                              \
  }

#define FOR_EACH DEFINE_FREQUENTLY_USED_TYPE
WELL_KNOWN_TYPES
#undef FOR_EACH

#define FOR_EACH DEFINE_FREQUENTLY_USED_FIELD
PRIMITIVE_PSEUDO_TYPE_FIELDS
#undef FOR_EACH
