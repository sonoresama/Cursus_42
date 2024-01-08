/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:30:06 by eorer             #+#    #+#             */
/*   Updated: 2024/01/08 19:15:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <sstream>
# include <string>

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

    void  sort(char **argv);

  private :
    void  _initList(char **argv);
    void  _initVector(char **argv);
    void  _sortList(PmergeMe* item);
    void  _sortVector(PmergeMe* item);
    void  _printList();
    void  _printVector();

    std::list<unsigned int> _list;
    std::vector<unsigned int> _vector;
};

#endif
