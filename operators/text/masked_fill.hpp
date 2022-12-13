// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "ocos.h"
#include "string_utils.h"
#include <unordered_map>

struct KernelMaskedFill : BaseKernel {
  KernelMaskedFill(const OrtApi& api, const OrtKernelInfo* info);
  void Compute(OrtKernelContext* context);
 private:
  std::unordered_map<std::string, std::string> map_;
};

struct CustomOpMaskedFill : OrtW::CustomOpBase<CustomOpMaskedFill, KernelMaskedFill> {
  void* CreateKernel(const OrtApi& api, const OrtKernelInfo* info) const;
  const char* GetName() const;
  size_t GetInputTypeCount() const;
  ONNXTensorElementDataType GetInputType(size_t index) const;
  size_t GetOutputTypeCount() const;
  ONNXTensorElementDataType GetOutputType(size_t index) const;
};
