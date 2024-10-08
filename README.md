# Leetcode Problems 1 - 10 in baabnq
This repository aims to provide examples of baabnq being used to solve quote unquote real problems.
Leetcode problems 1 - 10 are used here because they are both small and easy to understand, but still require some actual work to get running,
as opposed to other, more generic examples, like Hello World or Fibonacci.


If you have trouble understanding what's going on here, check out the [Learning and Quickstart Page](https://baabnq.github.io/learning/).

## Structure
There's a directory per problem, with each one containing:
- main.baabnq - the baabnq solution
- proto.c     - a C prototype of the solution
- prob.md     - a copy of the problem statement for reference

## Running
### Requirements
- python 3.8.5 and above
- git

### Execution
Assuming Baabnq has been set up in the current work directory. <br>
If you don't have Baabnq set up, you can use the [Development Kit](https://github.com/baabnq/kit) to do so.
```
git clone https://github.com/baabnq/leetcode-examples
python compi.py -i leetcode-examples/<problem directory>/main.baabnq
python vm.py -f build.s1
``` 
