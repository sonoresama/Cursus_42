/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:30:06 by eorer             #+#    #+#             */
/*   Updated: 2024/01/09 17:08:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <sstream>
# include <string>
# include <algorithm>
# include <ctime>

# define LIST std::list<unsigned int>
# define LIST_ITERATOR std::list<unsigned int>::iterator
# define VECTOR std::vector<unsigned int>
# define VECTOR_ITERATOR std::vector<unsigned int>::iterator

class PmergeMe 
{
  public :
    PmergeMe();
    PmergeMe(std::list<unsigned int> lst);
    PmergeMe(std::vector<unsigned int> vec);
    PmergeMe(const PmergeMe& cpy);
    PmergeMe& operator=(const PmergeMe& cpy);
    ~PmergeMe();

    class StringStreamError : public std::exception
    {
      const char* what() const throw();
    };

    class NegativeNumberError : public std::exception
    {
      const char* what() const throw();
    };

    void  sort(char **argv);
    void  _printList(LIST lst);
    void  _printVector(VECTOR vec);

  private :
    void  _initList(char **argv);
    void  _initVector(char **argv);
    LIST  _sortList(LIST lst);
    VECTOR  _sortVector(VECTOR vec);

    std::list<unsigned int> _list;
    std::vector<unsigned int> _vector;
};

#endif
