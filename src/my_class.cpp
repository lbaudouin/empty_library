// -------------------------------------------------
//
// one line to give the library's name and an idea of what it does.
// Copyright (C) year  name of author
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
// -------------------------------------------------

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

