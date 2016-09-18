# KMapSolver
Qt C++ and Lepton Based K-Map solver for unlimited variables

# Demo

## 1. Simplify: `(A + C)(AD + AD) + AC + C`

![1](http://i.imgur.com/8eMw0Wx.png)

## 2. Simplify: `A(A + B) + (B + AA)(A + B)`

![2](http://i.imgur.com/8LRLDTm.png)

## 3. Simplify: `a'b'c + a'bc' + ab'c' + ab'c + abc' + abc`

![3](http://i.imgur.com/TnmL3CF.png)

# Check Solution

1, 2: http://sandbox.mc.edu/~bennet/cs110/boolalg/simple.html

3: http://babbage.cs.qc.cuny.edu/courses/Minimize/

# Reference:

Thanks to [Abdelrahman Elzedy](http://www.codeproject.com/script/Membership/View.aspx?mid=9729999) for the core [KMap Minimizer Program for infinite variables](http://www.codeproject.com/Articles/649849/A-Cplusplus-Karnaugh-Map-Minimizer-Infinite-Variab).
