## for taking input
- int x;
- cin >> x;

## For printing output
- cout << "The value x: " << x

## All function lie iniside std::
- so use namespace to avoid it writinng everytime

## For ending a print ln and go to new line
- "/n" or endl

## For including all libraries 
-  #include<bits/stdc++.h>

## Data type
- int --> -10^9 to 10^9
- long --> -10^12 to 10^12
- long long ---> larger number --> -10^18 to 10^18
- float
- double 
- long double


<!-- String -->
- string --> it will take input upto whitespace
- so in order to get the whole line as input use getline()
- ex: 

``` cpp
    string s;
    getline(cin, s);
    cout << str;
```

- char --> for taking characters


## If else statement
- grade problem
- voting age problem
- Job eligiblity problem

## Switch case 
- weekday problem

## Array
#### 1D:
- int arr[size]
#### 2D:
- int arr[n][m]

## String
- String st
-st[0]

## For Loop

## while Loop

## do..while loop
- code must run min of 1 time

## Function (pass by reference & )
- void -> which does not return anything
- return
- parameterized
- non parameterized

#### pass by value
- when any number passed by value then the original no. is not passsed only a copy of it is passed, so when we do some opertions on the coped value it doesn't affect the original num

``` cpp
int updatedNum(int num) {
    num += 10;
    return num;
}

int main() {
    int a;
    cin >> a;
    cout << updatedNum(a) << endl;
    cout << a;
    return 0;
}

```

#### pass by reference
- when any number passed by referencce then the original value is passsed, so when we do some opertions on the ref value it updated the original num.

- add <b>&</b> to the passed varibale
``` cpp

int updatedNum(int &num) {
    num += 10;
    return num;
}

int main() {
    int a;
    cin >> a;
    cout << updatedNum(a) << endl;
    cout << a;
    return 0;
}

```

#### Array is always passed by reference , but dont use & to pass



## Time Complexity
- Time complexity != time taken
- TC: rate at which the time taken increase with respect to the input size
- TC: considered it in terms of worst case scenerios
- avoid constants
- avoid lower values

### Big- Oh Notation --> worst case / upper bound

### Theta Notation --> average case / middle bound

### Omega Notation --> best case / lower bound


## Time Complexity
- Space complexity = auxillary space (space that taken to solve the problem) + input space (space that taken to store the input)
- TC: rate at which the time taken increase with respect to the input size
- TC: considered it in terms of worst case scenerios
- avoid constants
- avoid lower values


# STL (Standard Template Library)
- It is divided into 4 parts:
1. Algorithms
2. Containers
3. Functions
4. Iterators


## Pairs
- stores two values of diff types into a single object
- it is a part of utiliy library

### Initialize

1. First Way
``` cpp
    pair <int, int> p = {1, 4};
    pair <int, pair <int,int>> p = {1, {2, 4}};

```

2. Second Way
``` cpp
    make_pair(2, "Two");
```     
### Access value

``` cpp
    cout << p.first << " " << p.second ;
    cout << p.first << " " << p.second.first ;
``` 

### Pair Array
- we can create array of pair
``` cpp
    pair<int, int> arr[] = {{1,2}, {3,4}, {5,6},  {7,8}};
    cout << arr[1].first << " " << arr[1].second;
```


# Vectors
- vector is  a container of dynamic size that can grow
- it is a part of of vector library

### Initialize

1. First Way
``` cpp
    

```

2. Second Way
``` cpp
    make_pair(2, "Two");
```     
### Access value

``` cpp
    cout << p.first << " " << p.second ;
    cout << p.first << " " << p.second.first ;
``` 

