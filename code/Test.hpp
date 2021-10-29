
#pragma once

/*!
  @file Test.hpp
 */

/*!
  @def PROJECT_NAME
  @brief the define of PROJECT_NAME
 */
#define PROJECT_NAME "GenT"

/*!
  @typedef funp
  @brief typedef funp
 */
typedef void (*funp)(bool a);

/*!
  @struct Info
  @brief info struct
 */
struct Info{
  int m_index;   /**< index */
  bool m_ready;  /**< ready flag */
}Info; 

/*!
  @enum EType
  @brief type of E
 */
enum EType{
  E_A,          /**< type A */
  E_B,          /**< type B */
};

/*!
  function call
 */
void call(bool isOK);

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

/*!
  @page page_root Root
  main page...
  | key   | value |
  | :---- | :---- |
  | 123   | ABC   |
  | 456   | QWE   |
  | 789   | SDF   |
  - @subpage page_A "A"
  @copybrief page_A
  - @subpage page_B "B"
  @copybrief page_B
  - @subpage page_C "C"
  @copybrief page_C
 */

 /*!
   @page page_A A
   @brief this is A
  */

   /*!
   @page page_B B
   @brief this is B
  */
  
  /*!
   @page page_C C
   @brief this is C
  */