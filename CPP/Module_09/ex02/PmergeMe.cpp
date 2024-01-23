/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:37:04 by eorer             #+#    #+#             */
/*   Updated: 2024/01/11 18:17:30 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

  //CANON
PmergeMe::PmergeMe()
{
  std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(std::list<unsigned int> lst) : _list(lst)
{
  std::cout << "List constructor called" << std::endl;
}

PmergeMe::PmergeMe(std::vector<unsigned int> vec) : _vector(vec)
{
  std::cout << "Vector constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
  std::cout << "Cpy constructor called" << std::endl;
  *this = cpy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy)
{
  if (this == &cpy)
    return (*this);
  this->_list = cpy._list;
  this->_vector = cpy._vector;
  return (*this);
}

PmergeMe::~PmergeMe()
{
  std::cout << "Destructor called" << std::endl;
}

void  PmergeMe::sort(char **argv)
{
  clock_t l_start;
  clock_t v_start;
  clock_t l_end;
  clock_t v_end;
  LIST  l_tmp;
  VECTOR  v_tmp;

  this->_initList(argv);
  l_tmp = this->_list;
  l_start = clock();
  this->_list = _sortList(this->_list);
  l_end = clock();

  this->_initVector(argv);
  v_tmp = this->_vector;
  v_start = clock();
  this->_vector = _sortVector(this->_vector);
  v_end = clock();

  std::cout << "Before : ";
  this->_printList(l_tmp);
  std::cout << std::endl;
  std::cout << "After : ";
  this->_printList(this->_list);
  std::cout << std::endl;
  std::cout << "Time used to process " << this->_list.size() << " elements by std::list : " << static_cast<double>(l_end - l_start) / CLOCKS_PER_SEC * 1e6 << " μs" << std::endl;
  std::cout << "Time used to process " << this->_vector.size() << " elements by std::vector : " << static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1e6 << " μs" << std::endl;
}

void  PmergeMe::_initList(char **argv)
{
  std::string str;
  std::istringstream  iss;
  long int num;

  for (int i = 1; argv[i]; i++)
  {
    str = static_cast<std::string>(argv[i]);
    iss.str(str);
    iss >> num;
    if (iss.fail())
      throw PmergeMe::StringStreamError();
    else if (num < 0)
      throw PmergeMe::NegativeNumberError();
    this->_list.push_back(static_cast<unsigned int>(num));
    iss.clear();
  }
}

void  PmergeMe::_initVector(char **argv)
{
  std::string str;
  std::istringstream  iss;
  long int num;

  for (int i = 1; argv[i]; i++)
  {
    str = static_cast<std::string>(argv[i]);
    iss.str(str);
    iss >> num;
    if (iss.fail())
      throw PmergeMe::StringStreamError();
    else if (num < 0)
      throw PmergeMe::NegativeNumberError();
    this->_vector.push_back(static_cast<unsigned int>(num));
    iss.clear();
  }
}

LIST  PmergeMe::_sortList(LIST lst)
{
  LIST                         mainChain;
  LIST                         subChain;
  LIST_ITERATOR                    next;
  long int                                         last = -1;

  if (lst.size() <= 2)
  {
    if (lst.front() > lst.back())
      std::swap(lst.front(), lst.back());
    return (lst);
  }
  for (LIST_ITERATOR it = lst.begin(); it != lst.end(); ++it)
  {
    next = it;
    next++;
    if (next == lst.end())
    {
      last = *it;
      break;
    }
    if (*it > *next)
    {
      mainChain.push_back(*it);
      subChain.push_back(*(++it));
    }
    else
    {
      subChain.push_back(*it);
      mainChain.push_back(*(++it));
    }
  }
  mainChain = _sortList(mainChain);
  for (LIST_ITERATOR it = subChain.begin(); it != subChain.end(); ++it)
  {
    mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), *it), *it);
  }
  if (last != -1)
   mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), last), static_cast<unsigned int>(last));
  return (mainChain);
}

VECTOR  PmergeMe::_sortVector(VECTOR vec)
{
  VECTOR                         mainChain;
  VECTOR                         subChain;
  VECTOR_ITERATOR                    next;
  long int                                         last = -1;

  if (vec.size() <= 2)
  {
    if (vec.front() > vec.back())
      std::swap(vec.front(), vec.back());
    return (vec);
  }
  for (VECTOR_ITERATOR it = vec.begin(); it != vec.end(); ++it)
  {
    next = it;
    next++;
    if (next == vec.end())
    {
      last = *it;
      break;
    }
    if (*it > *next)
    {
      mainChain.push_back(*it);
      subChain.push_back(*(++it));
    }
    else
    {
      subChain.push_back(*it);
      mainChain.push_back(*(++it));
    }
  }
  mainChain = _sortVector(mainChain);
  for (VECTOR_ITERATOR it = subChain.begin(); it != subChain.end(); ++it)
  {
    mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), *it), *it);
  }
  if (last != -1)
   mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), last), static_cast<unsigned int>(last));
  return (mainChain);
}

  //PRINT
void  PmergeMe::_printList(LIST lst)
{
  for (std::list<unsigned int>::iterator it = lst.begin(); it != lst.end(); ++it)
    std::cout << *it << " ";
}

void  PmergeMe::_printVector(VECTOR vec)
{
  for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout << *it << " ";
}

const char* PmergeMe::StringStreamError::what() const throw()
{
  return ("String stream extraction failed");
}

const char* PmergeMe::NegativeNumberError::what() const throw()
{
  return ("Negative Number");
}
