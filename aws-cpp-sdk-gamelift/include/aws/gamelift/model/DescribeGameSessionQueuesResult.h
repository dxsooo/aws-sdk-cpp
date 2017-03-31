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
#pragma once
#include <aws/gamelift/GameLift_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/gamelift/model/GameSessionQueue.h>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace GameLift
{
namespace Model
{
  class AWS_GAMELIFT_API DescribeGameSessionQueuesResult
  {
  public:
    DescribeGameSessionQueuesResult();
    DescribeGameSessionQueuesResult(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    DescribeGameSessionQueuesResult& operator=(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);

    /**
     * <p>Collection of objects that describes the requested game session queues.</p>
     */
    inline const Aws::Vector<GameSessionQueue>& GetGameSessionQueues() const{ return m_gameSessionQueues; }

    /**
     * <p>Collection of objects that describes the requested game session queues.</p>
     */
    inline void SetGameSessionQueues(const Aws::Vector<GameSessionQueue>& value) { m_gameSessionQueues = value; }

    /**
     * <p>Collection of objects that describes the requested game session queues.</p>
     */
    inline void SetGameSessionQueues(Aws::Vector<GameSessionQueue>&& value) { m_gameSessionQueues = value; }

    /**
     * <p>Collection of objects that describes the requested game session queues.</p>
     */
    inline DescribeGameSessionQueuesResult& WithGameSessionQueues(const Aws::Vector<GameSessionQueue>& value) { SetGameSessionQueues(value); return *this;}

    /**
     * <p>Collection of objects that describes the requested game session queues.</p>
     */
    inline DescribeGameSessionQueuesResult& WithGameSessionQueues(Aws::Vector<GameSessionQueue>&& value) { SetGameSessionQueues(value); return *this;}

    /**
     * <p>Collection of objects that describes the requested game session queues.</p>
     */
    inline DescribeGameSessionQueuesResult& AddGameSessionQueues(const GameSessionQueue& value) { m_gameSessionQueues.push_back(value); return *this; }

    /**
     * <p>Collection of objects that describes the requested game session queues.</p>
     */
    inline DescribeGameSessionQueuesResult& AddGameSessionQueues(GameSessionQueue&& value) { m_gameSessionQueues.push_back(value); return *this; }

    /**
     * <p>Token that indicates where to resume retrieving results on the next call to
     * this action. If no token is returned, these results represent the end of the
     * list.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>Token that indicates where to resume retrieving results on the next call to
     * this action. If no token is returned, these results represent the end of the
     * list.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>Token that indicates where to resume retrieving results on the next call to
     * this action. If no token is returned, these results represent the end of the
     * list.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = value; }

    /**
     * <p>Token that indicates where to resume retrieving results on the next call to
     * this action. If no token is returned, these results represent the end of the
     * list.</p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>Token that indicates where to resume retrieving results on the next call to
     * this action. If no token is returned, these results represent the end of the
     * list.</p>
     */
    inline DescribeGameSessionQueuesResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>Token that indicates where to resume retrieving results on the next call to
     * this action. If no token is returned, these results represent the end of the
     * list.</p>
     */
    inline DescribeGameSessionQueuesResult& WithNextToken(Aws::String&& value) { SetNextToken(value); return *this;}

    /**
     * <p>Token that indicates where to resume retrieving results on the next call to
     * this action. If no token is returned, these results represent the end of the
     * list.</p>
     */
    inline DescribeGameSessionQueuesResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:
    Aws::Vector<GameSessionQueue> m_gameSessionQueues;
    Aws::String m_nextToken;
  };

} // namespace Model
} // namespace GameLift
} // namespace Aws
