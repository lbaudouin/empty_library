#include "my_class.h"

/** Create MyClass object
 */
MyClass::MyClass() : m_sentence("")
{

}

/** Destroy MyClass object
 */
MyClass::~MyClass()
{

}

/** Add a word at the end
 * @param word is the word to add
 * @return Size of sentence
 */
int MyClass::addWord(std::string word)
{
  if(m_sentence.size()!=0)
    m_sentence.push_back(' ');
  m_sentence.append(word);
  return m_sentence.size();
}

/** Get the sentence
 * @return The sentence
 */
std::string MyClass::getString() const
{
  return m_sentence;
}

