/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:49:39 by prambaud          #+#    #+#             */
/*   Updated: 2025/04/04 16:50:51 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void showVec2(std::deque<int> vec_big) {
    size_t k = 0;
    while ( k < vec_big.size()) {
        std::cout << vec_big[k] << ", ";
        k++;
    }
}

void showVecVec2(std::deque<std::deque<int> > vec_big) {
    for (std::size_t k = 0; k < vec_big.size(); ++k) {
        std::cout << "[ " ;
        showVec2(vec_big[k]);
        std::cout << "] " ;
    }
    std::cout << std::endl;
}

void ft_swap2(int &a, int &b) {
    int temp(0);
    temp = a;
    a = b;
    b = temp;
}

// on compare l element le plus a droite de chaque "pair" puis on swap les deux pairs
void ft_sortPairsSizeK2(std::deque<int> &vec, size_t k) {
    size_t i = 0;
    size_t j(0);
    if (vec.size() < 2 * k)
        return;
    while (i + 2 * k <= vec.size()) 
    {
        if (vec[i + k - 1] > vec[i + 2*k - 1]) {
            while(j < k) {
                ft_swap2(vec[i + j], vec[i + k + j]);
                j++;
            }
        }
        j = 0;
        i += 2*k; 
    }
}

//on appelle en recurcif la fonction du de sorting par "pair"
void ft_recursiveSort2(std::deque<int> &vec, size_t k) {
    if (k == 0 || vec.size() < 2 * k)
        return;
    ft_sortPairsSizeK2(vec, k);
    ft_recursiveSort2(vec, 2 * k);
}


//insertion en tri binair du main dans le pend ++ Jackobstal
void ft_binarysorting2(std::deque<std::deque<int> > &main, std::deque<std::deque<int> > &pend)
{
    if(pend.size() == 0)
        return;
    std::deque<int> minipend = pend[0]; // incide 0 fait separement
    int val = minipend.back();
    size_t left = 0;
    size_t right = main.size();
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (main[mid].back() < val)
            left = mid + 1;
        else
            right = mid;
    }
    main.insert(main.begin() + left, minipend);
    size_t i = 1;
    size_t j = 0;
    size_t temp[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971}; // suite de Jackobstal
    while (temp[i] < pend.size())
    {
        j = temp[i];
        while (j > temp[i - 1])
        {
            std::deque<int> minipend = pend[j];
            int val = minipend.back();
            size_t left = 0;
            size_t right = main.size();
            while (left < right)
            {
                size_t mid = left + (right - left) / 2;
                if (main[mid].back() < val)
                    left = mid + 1;
                else
                    right = mid;
            }
            main.insert(main.begin() + left, minipend); // revoie du bloc dans la bonne position
            j--; 
        }
        i++;
    }
    j = pend.size() - 1;
    while (j > temp[i - 1])
    {
        std::deque<int> minipend = pend[j];
        int val = minipend.back();
        size_t left = 0;
        size_t right = main.size();
        while (left < right)
        {
            size_t mid = left + (right - left) / 2;
            if (main[mid].back() < val)
                left = mid + 1;
            else
                right = mid;
        }
        main.insert(main.begin() + left, minipend); // revoie du bloc dans la bonne position
        j--; 
    }
    pend.clear();
}

//On renvoie dans vec2 les elements du main et de noparty apres que le pend ait ete reinserre 
void ft_clearVecAddBackAll2(std::deque<std::deque<int> > &vec2, std::deque<std::deque<int> > &main, std::deque<std::deque<int> > &noparty)
{
    vec2.clear();
    size_t i(0);
    while(i < main.size()) {
        vec2.push_back(main[i]);
        i++;
    }
    i = 0;
    while(i < noparty.size()) {
        vec2.push_back(noparty[i]);
        i++;
    }
    main.clear();
    noparty.clear();
}
//on split le main et le pend
void ftPendMainSplit2(std::deque<std::deque<int> > &vec2)
{
    std::deque<std::deque<int> > main;
    std::deque<std::deque<int> > pend;
    std::deque<std::deque<int> > noparty;
    size_t i = 1;
    if (vec2.size() <= 3)
        return;
    main.push_back(vec2[0]);
    if(vec2.size() % 2 == 0) {
        while (i + 1 < vec2.size()) // quand il y a une paire, on met le premier dans pend et l autre dans main
        {
            if(i % 2 != 0)
                main.push_back(vec2[i]);
            else
                pend.push_back(vec2[i]);
            i++; 
        }
        while (i < vec2.size())  // le rest va dans le noparty
        {
            noparty.push_back(vec2[i]);
            i++; 
        }
    }
    else { // s il y a un nombre impaire d element, pas besoin de noparty
        while (i < vec2.size()) // quand il y a une paire, on met le premier dans pend et l autre dans main
        {
            if(i % 2 != 0)
                main.push_back(vec2[i]);
            else
                pend.push_back(vec2[i]);
            i++; 
        }
    }
    if(pend.size() == 0 && noparty.size() == 0)
        return;
    ft_binarysorting2(main, pend);
    ft_clearVecAddBackAll2(vec2, main, noparty);
}

std::deque<std::deque<int> > ft_PmergeMe_vecvec2(std::deque<int> vec, size_t k) {
    std::deque<std::deque<int> > vec2;

    size_t i(0);
    size_t j(0);
    while (i < vec.size())
    {
        std::deque<int> block;
        while(j < k && (i + j) < vec.size())
        {
            block.push_back(vec[j + i]);
            j++;
        }
        vec2.push_back(block);
        j = 0;
        i = i + k;
    }
    ftPendMainSplit2(vec2);
    return(vec2);
}

void ft_backToSignleVec2(std::deque<int> *vec, std::deque<std::deque<int> > *vec2) {
    vec->clear();
    size_t i(0);
    size_t j(0);
    while(i < vec2->size())
    {
        while (j < (*vec2)[i].size())
        {
            vec->push_back((*vec2)[i][j]);
            j++;
        }
        j = 0;
        i++;
    }
    vec2->clear();
}
void ft_PmergeMe_deque(int ac, char **av) {
    clock_t start_time = clock();
    std::deque<int> vec;
    std::deque<std::deque<int> > vec2;
    int j(1);
    while(j < ac)
    {
        vec.push_back(atoi(av[j]));
        j++;
    }
    size_t i(0);
    while (i < vec.size() - 1)
    {
        if(vec[i] > vec[i + 1])
            ft_swap2(vec[i], vec[i + 1]);
        i += 2;
    }
    ft_recursiveSort2(vec, 2);
    size_t k(1);
    while(2*(k) < vec.size()) // repartir du plus "grand" nombre d element
        k = 2*k;
    k /= 2; 
    while(k > 0)
    {
        vec2 = ft_PmergeMe_vecvec2(vec, k); // on cree des groupes de k + on split main pend
        ft_backToSignleVec2(&vec, &vec2); // on recree vec a partir de ce qui a ete trie dans vec2
        k /= 2;
    }
    // std::cout << "After:  ";
    // i = 0;
    // while (i < vec.size())
    // {
    //     std::cout << " " << vec[i];
    //     i++;
    // }
    // std::cout << "\n";
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " 
    << (clock() - start_time) / (CLOCKS_PER_SEC / 1000000) << "us\n";
}
