// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file    DatDecoderSpec.h
/// \author  Andrea Ferrero
///
/// \brief Definition of a data processor to run the raw decoding
///

#ifndef DETECTORS_HMPID_WORKFLOW_INCLUDE_HMPIDWORKFLOW_DIGITSTOCLUSTERSPEC_H_
#define DETECTORS_HMPID_WORKFLOW_INCLUDE_HMPIDWORKFLOW_DIGITSTOCLUSTERSPEC_H_

#include "Framework/DataProcessorSpec.h"
#include "Framework/Task.h"

#include "HMPIDBase/Common.h"
#include "HMPIDReconstruction/Clusterer.h"
#include "Framework/WorkflowSpec.h"

namespace o2
{
namespace hmpid
{

class DigitsToClustersTask : public framework::Task
{
 public:
  DigitsToClustersTask() = default;
  ~DigitsToClustersTask() override = default;
  void init(framework::InitContext& ic) final;
  void run(framework::ProcessingContext& pc) final;
  void endOfStream(framework::EndOfStreamContext& ec) override;

 private:
  std::string mSigmaCutPar;
  float mSigmaCut[7] = {4, 4, 4, 4, 4, 4, 4};

  o2::hmpid::Clusterer* mRec;
  long mDigitsReceived;

  ExecutionTimer mExTimer;
  void strToFloatsSplit(std::string s, std::string delimiter, float* res, int maxElem = 7);
};

o2::framework::DataProcessorSpec getDigitsToClustersSpec(std::string inputSpec = "HMP/DIGITS");

} // end namespace hmpid
} // end namespace o2

#endif
