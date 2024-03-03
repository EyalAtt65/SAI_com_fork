/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saifec.h
 *
 * @brief   This module defines SAI Forwarding Equivalence Class (FEC) interface
 */

#if !defined (__SAIFEC_H_)
#define __SAIFEC_H_

#include <saitypes.h>

/**
 * @defgroup SAIFEC SAI - Forwarding Equivalence Class specific API definitions
 *
 * @{
 */

/**
 * @brief Attribute Id for SAI FEC object
 */
typedef enum _sai_fec_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_FEC_ATTR_START,

   /**
     * @brief Next hop or next hop group
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_NEXT_HOP, SAI_OBJECT_TYPE_NEXT_HOP_GROUP
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_FEC_ATTR_NEXT_HOP_ID = SAI_FEC_ATTR_START,

    /**
     * @brief End of attributes
     */
    SAI_FEC_ATTR_END,

    /** Custom range base value */
    SAI_FEC_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_FEC_ATTR_CUSTOM_RANGE_END

} sai_fec_attr_t;

/**
 * @brief Create FEC
 *
 * @param[out] fec_id FEC ID
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_fec_fn)(
        _Out_ sai_object_id_t *fec_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove FEC
 *
 * @param[in] fec_id FEC ID
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_fec_fn)(
        _In_ sai_object_id_t fec_id);

/**
 * @brief Set FEC attribute value
 *
 * @param[in] fec_id FEC ID
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_fec_attribute_fn)(
        _In_ sai_object_id_t fec_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get FEC attribute value
 *
 * @param[in] fec_id FEC ID
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_fec_attribute_fn)(
        _In_ sai_object_id_t fec_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief FEC methods table retrieved with sai_api_query()
 */
typedef struct _sai_fec_api_t
{
    sai_create_fec_fn         create_fec;
    sai_remove_fec_fn         remove_fec;
    sai_set_fec_attribute_fn  set_fec_attribute;
    sai_get_fec_attribute_fn  get_fec_attribute;
} sai_fec_api_t;


/**
 * @}
 */
#endif /** __SAIFEC_H_ */