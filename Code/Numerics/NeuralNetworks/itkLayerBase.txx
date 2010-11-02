/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkLayerBase_txx
#define __itkLayerBase_txx

#include "itkLayerBase.h"


namespace itk
{
namespace Statistics
{
static unsigned int INVALID_LAYER_ID=vcl_numeric_limits<unsigned int>::max();
template<class TMeasurementVector, class TTargetVector>
LayerBase<TMeasurementVector,TTargetVector>
::LayerBase()
{
  m_NumberOfNodes = 0;
  m_LayerId = INVALID_LAYER_ID;
  m_LayerTypeCode = INVALIDLAYER;
  m_InputWeightSet = 0;
  m_OutputWeightSet = 0;
  m_ActivationFunction = 0;
  m_NodeInputFunction = 0;
}

template<class TMeasurementVector, class TTargetVector>
LayerBase<TMeasurementVector,TTargetVector>
::~LayerBase()
{
}
template<class TMeasurementVector, class TTargetVector>
void
LayerBase<TMeasurementVector,TTargetVector>
::SetNumberOfNodes(unsigned int n)
{
  m_NumberOfNodes = n;
  this->Modified();
}

template<class TMeasurementVector, class TTargetVector>
unsigned int
LayerBase<TMeasurementVector,TTargetVector>
::GetNumberOfNodes() const
{
  return m_NumberOfNodes;
}

template<class TMeasurementVector, class TTargetVector>
void
LayerBase<TMeasurementVector,TTargetVector>
:: SetNodeInputFunction(InputFunctionInterfaceType* f)
{
  m_NodeInputFunction = f;
  this->Modified();
}

template<class TMeasurementVector, class TTargetVector>
void
LayerBase<TMeasurementVector,TTargetVector>
::SetTransferFunction(TransferFunctionInterfaceType* f)
{
  m_ActivationFunction = f;
  this->Modified();
}

template<class TMeasurementVector, class TTargetVector>
void
LayerBase<TMeasurementVector,TTargetVector>
::SetInputWeightSet(WeightSetInterfaceType* weightset)
{
  if(m_LayerId==INVALID_LAYER_ID)
    {
    itkExceptionMacro("ERROR:  Layer not added to network prior to weights being added.");
    }
  m_InputWeightSet=weightset;
  m_InputWeightSet->SetOutputLayerId(m_LayerId);
  this->Modified();
}

template<class TMeasurementVector, class TTargetVector>
void
LayerBase<TMeasurementVector,TTargetVector>
::SetOutputWeightSet(WeightSetInterfaceType* weightset)
{
  if(m_LayerId==INVALID_LAYER_ID)
    {
    itkExceptionMacro("ERROR:  Layer not added to network prior to weights being added.");
    }
  m_OutputWeightSet=weightset;
  m_OutputWeightSet->SetInputLayerId(m_LayerId);
  this->Modified();
}

/** Print the object */
template<class TMeasurementVector, class TTargetVector>
void
LayerBase<TMeasurementVector,TTargetVector>
::PrintSelf( std::ostream& os, Indent indent ) const
{
  os << indent << "BackPropagationLayer(" << this << ")" << std::endl;
  os << indent << "m_NumberOfNodes = " << m_NumberOfNodes << std::endl;
  os << indent << "m_LayerTypeCode = " << m_LayerTypeCode << std::endl;
  Superclass::PrintSelf( os, indent );
}

} // end namespace Statistics
} // end namespace itk

#endif
