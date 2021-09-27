
#pragma once

/*!
  @class Test
  @brief this the test calss
 */
class Test
{
public:
    /*!
      new  
     */
    Test();
 
    /*!
      destory
     */
    virtual ~Test();

    /*!
      add
    */
    virtual void add() = 0;
};