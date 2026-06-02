# Brute Force vs Optimization

Many Project Euler problems can technically be solved using brute force,
but become computationally infeasible as input sizes grow.

A recurring theme in these solutions is reducing the search space through:
- mathematical observations
- memoization
- divisibility properties
- symmetry
- prime decomposition

# Memoization

In problems involving repeated recursive structures,
previously computed results can be cached to avoid recomputation.

Example:
- Longest Collatz Sequence

Instead of recomputing chain lengths repeatedly,
previous chain lengths are stored and reused.

This transforms an exponential-style repeated computation
into a far more efficient dynamic programming approach.

# Prime Generation Optimization

Naive primality testing becomes extremely slow for large ranges.

Using the Sieve of Eratosthenes:
- reduces repeated divisibility checks
- generates all primes in near-linear time
- dramatically improves performance

Used in:
- Summation of Primes
- Largest Prime Factor

# Reducing Redundant Work

Several problems were improved by:
- avoiding repeated calculations
- reducing nested loops
- breaking early when conditions are satisfied
- reusing intermediate values

# Mathematical Reduction

Many Project Euler problems become significantly easier
once the underlying mathematical structure is identified.

Examples include:
- divisor properties
- arithmetic series
- prime factorization
- combinatorial counting
- symmetry in search spaces

# Handling Large Numbers

Some problems involve values exceeding standard integer ranges.

Approaches explored:
- modular arithmetic
- digit-by-digit computation
- string-based arithmetic
- reducing unnecessary growth of intermediate values

# Complexity Awareness

An important part of solving Project Euler problems
is understanding how complexity scales.

Several solutions were improved from:
- O(n²) → O(n log n)
- exponential recursion → memoized recursion
- repeated primality checks → sieve-based generation
