
#pragma once

/*!
  @def PROJECT_NAME
  @brief the define of PROJECT_NAME
 */
#define PROJECT_NAME "GenT"

/*!
  @typedef callBack
 */
typedef void (*callback)(bool);

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