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
#include <aws/es/model/DescribeElasticsearchInstanceTypeLimitsRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/http/URI.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::ElasticsearchService::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws::Http;

DescribeElasticsearchInstanceTypeLimitsRequest::DescribeElasticsearchInstanceTypeLimitsRequest() : 
    m_domainNameHasBeenSet(false),
    m_instanceType(ESPartitionInstanceType::NOT_SET),
    m_instanceTypeHasBeenSet(false),
    m_elasticsearchVersionHasBeenSet(false)
{
}

Aws::String DescribeElasticsearchInstanceTypeLimitsRequest::SerializePayload() const
{
  return "";
}

void DescribeElasticsearchInstanceTypeLimitsRequest::AddQueryStringParameters(URI& uri) const
{
    Aws::StringStream ss;
    if(m_domainNameHasBeenSet)
    {
      ss << m_domainName;
      uri.AddQueryStringParameter("domainName", ss.str());
      ss.str("");
    }

}



