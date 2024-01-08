/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:37:04 by eorer             #+#    #+#             */
/*   Updated: 2024/01/08 19:25:02 by eorer            ###   ########.fr       */
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
  //time
  this->_initList(argv);
  this->_sortList(this);
}

void  PmergeMe::_initList(char **argv)
{
  std::string str;
  std::istringstream  iss;
  unsigned int num;

  for (int i = 1; argv[i]; i++)
  {
    str = static_cast<std::string>(argv[i]);
    iss.str(str);
    iss >> num;
    if (iss.fail())
      throw PmergeMe::StringStreamError();
    this->_list.push_back(num);
    iss.clear();
  }
  this->_printList();
}

void  PmergeMe::_initVector(char **argv)
{
  std::string str;
  std::istringstream  iss;
  unsigned int num;

  for (int i = 1; argv[i]; i++)
  {
    str = static_cast<std::string>(argv[i]);
    iss.str(str);
    iss >> num;
    if (iss.fail())
      throw PmergeMe::StringStreamError();
    this->_vector.push_back(num);
    iss.clear();
  }
  this->_printVector();
}

void  PmergeMe::_sortList(PmergeMe* item)
{
  std::list<std::pair <unsigned int, unsigned int> >  pairs;
  std::list<unsigned int> mainChain;
  unsigned int  last;

  for (std::list<unsigned int>::iterator it = item->_list.begin(); it != item->_list.end(); ++it)
  {
    //A GERER !!!!!!!
    pairs.push_back(std::make_pair(*it, *(++it)));
    if (it == item->_list.end())
    {
      last = *it;
      std::cout << "Last : " << last << std::endl;
      break;
    }
  }
  for (std::list<std::pair<unsigned int, unsigned int> >::iterator its = pairs.begin(); its != pairs.end(); ++its)
  {
    if (its->first > its->second)
      mainChain.push_back(its->first);
    else
      mainChain.push_back(its->second);
    std::cout << its->first << " ";
    std::cout << its->second << std::endl;
  }
}

void  PmergeMe::_sortVector(PmergeMe* item)
{
  (void)item;
}

  //PRINT
void  PmergeMe::_printList()
{
  std::cout << "List : ";
  for (std::list<unsigned int>::iterator it = this->_list.begin(); it != this->_list.end(); ++it)
    std::cout << *it << " ";
  std::cout << '\n';
}

void  PmergeMe::_printVector()
{
  std::cout << "Vector : ";
  for (std::vector<unsigned int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
    std::cout << *it << " ";
  std::cout << '\n';
}

const char* PmergeMe::StringStreamError::what() const throw()
{
  return ("String stream extraction failed");
}
