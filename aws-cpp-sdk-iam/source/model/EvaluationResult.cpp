﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/iam/model/EvaluationResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace IAM
{
namespace Model
{

EvaluationResult::EvaluationResult() : 
    m_evalActionNameHasBeenSet(false),
    m_evalResourceNameHasBeenSet(false),
    m_evalDecision(PolicyEvaluationDecisionType::NOT_SET),
    m_evalDecisionHasBeenSet(false),
    m_matchedStatementsHasBeenSet(false),
    m_missingContextValuesHasBeenSet(false),
    m_organizationsDecisionDetailHasBeenSet(false),
    m_evalDecisionDetailsHasBeenSet(false),
    m_resourceSpecificResultsHasBeenSet(false)
{
}

EvaluationResult::EvaluationResult(const XmlNode& xmlNode) : 
    m_evalActionNameHasBeenSet(false),
    m_evalResourceNameHasBeenSet(false),
    m_evalDecision(PolicyEvaluationDecisionType::NOT_SET),
    m_evalDecisionHasBeenSet(false),
    m_matchedStatementsHasBeenSet(false),
    m_missingContextValuesHasBeenSet(false),
    m_organizationsDecisionDetailHasBeenSet(false),
    m_evalDecisionDetailsHasBeenSet(false),
    m_resourceSpecificResultsHasBeenSet(false)
{
  *this = xmlNode;
}

EvaluationResult& EvaluationResult::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode evalActionNameNode = resultNode.FirstChild("EvalActionName");
    if(!evalActionNameNode.IsNull())
    {
      m_evalActionName = StringUtils::Trim(evalActionNameNode.GetText().c_str());
      m_evalActionNameHasBeenSet = true;
    }
    XmlNode evalResourceNameNode = resultNode.FirstChild("EvalResourceName");
    if(!evalResourceNameNode.IsNull())
    {
      m_evalResourceName = StringUtils::Trim(evalResourceNameNode.GetText().c_str());
      m_evalResourceNameHasBeenSet = true;
    }
    XmlNode evalDecisionNode = resultNode.FirstChild("EvalDecision");
    if(!evalDecisionNode.IsNull())
    {
      m_evalDecision = PolicyEvaluationDecisionTypeMapper::GetPolicyEvaluationDecisionTypeForName(StringUtils::Trim(evalDecisionNode.GetText().c_str()).c_str());
      m_evalDecisionHasBeenSet = true;
    }
    XmlNode matchedStatementsNode = resultNode.FirstChild("MatchedStatements");
    if(!matchedStatementsNode.IsNull())
    {
      XmlNode matchedStatementsMember = matchedStatementsNode.FirstChild("member");
      while(!matchedStatementsMember.IsNull())
      {
        m_matchedStatements.push_back(matchedStatementsMember);
        matchedStatementsMember = matchedStatementsMember.NextNode("member");
      }

      m_matchedStatementsHasBeenSet = true;
    }
    XmlNode missingContextValuesNode = resultNode.FirstChild("MissingContextValues");
    if(!missingContextValuesNode.IsNull())
    {
      XmlNode missingContextValuesMember = missingContextValuesNode.FirstChild("member");
      while(!missingContextValuesMember.IsNull())
      {
        m_missingContextValues.push_back(StringUtils::Trim(missingContextValuesMember.GetText().c_str()));
        missingContextValuesMember = missingContextValuesMember.NextNode("member");
      }

      m_missingContextValuesHasBeenSet = true;
    }
    XmlNode organizationsDecisionDetailNode = resultNode.FirstChild("OrganizationsDecisionDetail");
    if(!organizationsDecisionDetailNode.IsNull())
    {
      m_organizationsDecisionDetail = organizationsDecisionDetailNode;
      m_organizationsDecisionDetailHasBeenSet = true;
    }
    XmlNode evalDecisionDetailsNode = resultNode.FirstChild("EvalDecisionDetails");

    if(!evalDecisionDetailsNode.IsNull())
    {
      XmlNode evalDecisionDetailsEntry = evalDecisionDetailsNode.FirstChild("entry");
      while(!evalDecisionDetailsEntry.IsNull())
      {
        XmlNode keyNode = evalDecisionDetailsEntry.FirstChild("key");
        XmlNode valueNode = evalDecisionDetailsEntry.FirstChild("value");
        m_evalDecisionDetails[StringUtils::Trim(keyNode.GetText().c_str())] =
            PolicyEvaluationDecisionTypeMapper::GetPolicyEvaluationDecisionTypeForName(StringUtils::Trim(valueNode.GetText().c_str()));
        evalDecisionDetailsEntry = evalDecisionDetailsEntry.NextNode("entry");
      }

      m_evalDecisionDetailsHasBeenSet = true;
    }
    XmlNode resourceSpecificResultsNode = resultNode.FirstChild("ResourceSpecificResults");
    if(!resourceSpecificResultsNode.IsNull())
    {
      XmlNode resourceSpecificResultsMember = resourceSpecificResultsNode.FirstChild("member");
      while(!resourceSpecificResultsMember.IsNull())
      {
        m_resourceSpecificResults.push_back(resourceSpecificResultsMember);
        resourceSpecificResultsMember = resourceSpecificResultsMember.NextNode("member");
      }

      m_resourceSpecificResultsHasBeenSet = true;
    }
  }

  return *this;
}

void EvaluationResult::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_evalActionNameHasBeenSet)
  {
      oStream << location << index << locationValue << ".EvalActionName=" << StringUtils::URLEncode(m_evalActionName.c_str()) << "&";
  }

  if(m_evalResourceNameHasBeenSet)
  {
      oStream << location << index << locationValue << ".EvalResourceName=" << StringUtils::URLEncode(m_evalResourceName.c_str()) << "&";
  }

  if(m_evalDecisionHasBeenSet)
  {
      oStream << location << index << locationValue << ".EvalDecision=" << PolicyEvaluationDecisionTypeMapper::GetNameForPolicyEvaluationDecisionType(m_evalDecision) << "&";
  }

  if(m_matchedStatementsHasBeenSet)
  {
      unsigned matchedStatementsIdx = 1;
      for(auto& item : m_matchedStatements)
      {
        Aws::StringStream matchedStatementsSs;
        matchedStatementsSs << location << index << locationValue << ".MatchedStatements.member." << matchedStatementsIdx++;
        item.OutputToStream(oStream, matchedStatementsSs.str().c_str());
      }
  }

  if(m_missingContextValuesHasBeenSet)
  {
      unsigned missingContextValuesIdx = 1;
      for(auto& item : m_missingContextValues)
      {
        oStream << location << index << locationValue << ".MissingContextValues.member." << missingContextValuesIdx++ << "=" << StringUtils::URLEncode(item.c_str()) << "&";
      }
  }

  if(m_organizationsDecisionDetailHasBeenSet)
  {
      Aws::StringStream organizationsDecisionDetailLocationAndMemberSs;
      organizationsDecisionDetailLocationAndMemberSs << location << index << locationValue << ".OrganizationsDecisionDetail";
      m_organizationsDecisionDetail.OutputToStream(oStream, organizationsDecisionDetailLocationAndMemberSs.str().c_str());
  }

  if(m_evalDecisionDetailsHasBeenSet)
  {
      unsigned evalDecisionDetailsIdx = 1;
      for(auto& item : m_evalDecisionDetails)
      {
        oStream << location << index << locationValue << ".EvalDecisionDetails.entry." << evalDecisionDetailsIdx << ".key="
            << StringUtils::URLEncode(item.first.c_str()) << "&";
        oStream << location << index << locationValue << ".EvalDecisionDetails.entry." << evalDecisionDetailsIdx << ".value="
            << StringUtils::URLEncode(PolicyEvaluationDecisionTypeMapper::GetNameForPolicyEvaluationDecisionType(item.second).c_str()) << "&";
        evalDecisionDetailsIdx++;
      }
  }

  if(m_resourceSpecificResultsHasBeenSet)
  {
      unsigned resourceSpecificResultsIdx = 1;
      for(auto& item : m_resourceSpecificResults)
      {
        Aws::StringStream resourceSpecificResultsSs;
        resourceSpecificResultsSs << location << index << locationValue << ".ResourceSpecificResults.member." << resourceSpecificResultsIdx++;
        item.OutputToStream(oStream, resourceSpecificResultsSs.str().c_str());
      }
  }

}

void EvaluationResult::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_evalActionNameHasBeenSet)
  {
      oStream << location << ".EvalActionName=" << StringUtils::URLEncode(m_evalActionName.c_str()) << "&";
  }
  if(m_evalResourceNameHasBeenSet)
  {
      oStream << location << ".EvalResourceName=" << StringUtils::URLEncode(m_evalResourceName.c_str()) << "&";
  }
  if(m_evalDecisionHasBeenSet)
  {
      oStream << location << ".EvalDecision=" << PolicyEvaluationDecisionTypeMapper::GetNameForPolicyEvaluationDecisionType(m_evalDecision) << "&";
  }
  if(m_matchedStatementsHasBeenSet)
  {
      unsigned matchedStatementsIdx = 1;
      for(auto& item : m_matchedStatements)
      {
        Aws::StringStream matchedStatementsSs;
        matchedStatementsSs << location <<  ".MatchedStatements.member." << matchedStatementsIdx++;
        item.OutputToStream(oStream, matchedStatementsSs.str().c_str());
      }
  }
  if(m_missingContextValuesHasBeenSet)
  {
      unsigned missingContextValuesIdx = 1;
      for(auto& item : m_missingContextValues)
      {
        oStream << location << ".MissingContextValues.member." << missingContextValuesIdx++ << "=" << StringUtils::URLEncode(item.c_str()) << "&";
      }
  }
  if(m_organizationsDecisionDetailHasBeenSet)
  {
      Aws::String organizationsDecisionDetailLocationAndMember(location);
      organizationsDecisionDetailLocationAndMember += ".OrganizationsDecisionDetail";
      m_organizationsDecisionDetail.OutputToStream(oStream, organizationsDecisionDetailLocationAndMember.c_str());
  }
  if(m_evalDecisionDetailsHasBeenSet)
  {
      unsigned evalDecisionDetailsIdx = 1;
      for(auto& item : m_evalDecisionDetails)
      {
        oStream << location << ".EvalDecisionDetails.entry."  << evalDecisionDetailsIdx << ".key="
            << StringUtils::URLEncode(item.first.c_str()) << "&";
        oStream << location <<  ".EvalDecisionDetails.entry." << evalDecisionDetailsIdx << ".value="
            << StringUtils::URLEncode(PolicyEvaluationDecisionTypeMapper::GetNameForPolicyEvaluationDecisionType(item.second).c_str()) << "&";
        evalDecisionDetailsIdx++;
      }

  }
  if(m_resourceSpecificResultsHasBeenSet)
  {
      unsigned resourceSpecificResultsIdx = 1;
      for(auto& item : m_resourceSpecificResults)
      {
        Aws::StringStream resourceSpecificResultsSs;
        resourceSpecificResultsSs << location <<  ".ResourceSpecificResults.member." << resourceSpecificResultsIdx++;
        item.OutputToStream(oStream, resourceSpecificResultsSs.str().c_str());
      }
  }
}

} // namespace Model
} // namespace IAM
} // namespace Aws
