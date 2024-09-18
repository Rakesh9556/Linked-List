## File open and close
```cpp
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

```

## Modular Arithematics
- (a + b) mod m = (a mod m + b mod m) mod m
- (a − b) mod m = (a mod m − b mod m) mod m
- (a · b) mod m = (a mod m · b mod m) mod m

## Check two floating point no. is equal or not
```cpp
if (abs(a-b) < 1e-9) {
// a and b are equal
}
```

## Shortening code
- typedef : used to give a short name to a data type

```cpp
typedef long long ll;  // this will defin long long name as ll
// example
ll a = 123456789;
```

- macro: another way to shorten code
- specifies that certain strings in the code wil be changed before compilition
- used with #define keyword

```cpp
#define F first
#define S second
#define PB push_back
#define MP make_pair


// before
v.push_back(make_pair(y1,x1));
v.push_back(make_pair(y2,x2));
int d = v[i].first+v[i].second;

//after
v.PB(MP(y1,x1));
v.PB(MP(y2,x2));
int d = v[i].F+v[i].S;

```
- it can also used to shorten loop
```cpp
#define REP(i,a,b) for (int i = a; i <= b; i++)


// before
for (int i = 1; i <= n; i++) {
search(i);
}

//after
REP(i,1,n) {
search(i);
}

```


## Recursive Algorithms
#### 1. Generating Subset
- search(i): generate subsets
- subset vector:  for storing subsets