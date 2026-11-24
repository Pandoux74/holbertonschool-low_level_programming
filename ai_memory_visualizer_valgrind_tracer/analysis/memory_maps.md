## 3. Heap Example

### Execution and observed results

The program was executed normally without Valgrind.

The following output was observed:

```text
heap_example: allocations and a deliberate leak
alice=0x5e17d14a6420 name=0x5e17d14a6440 age=30
bob=0x5e17d14a6460 name=0x5e17d14a6480 age=41
```

### Step 1: Initial state

```text
STACK - main()
    alice = NULL
    bob = NULL

HEAP
    No explicit allocation yet.
```

### Step 2: Dynamic allocations

The function person_new() allocates memory for a Person structure at line 14 and a separate character array at line 21.

After both successful calls, four separate heap allocations exist.

```text
STACK - main()
    alice -> 0x5e17d14a6420
    bob   -> 0x5e17d14a6460

HEAP
    0x5e17d14a6420
        name -> 0x5e17d14a6440
        age = 30

    0x5e17d14a6440
        "Alice\0" (6 bytes)

    0x5e17d14a6460
        name -> 0x5e17d14a6480
        age = 41

    0x5e17d14a6480
        "Bob\0" (4 bytes)
```

The local variables of person_new() end their lifetime when the function returns. The dynamically allocated objects remain alive.

### Step 3: Bob's deallocation

At lines 66 and 67, both allocations associated with Bob are released.

```text
free(bob->name);
free(bob);
```

The character array and the Person structure both end their lifetime.

### Step 4: Alice's partial deallocation

At line 69, person_free_partial(alice) is called.

This function only releases the Person structure at line 41.

```text
STACK - main()
    alice: dangling pointer
    bob: dangling pointer

HEAP
    Alice structure: released
    Alice name: still allocated (6 bytes)
    Bob structure: released
    Bob name: released
```

Alice's name remains allocated, but the program has lost its valid reference to this allocation.

This creates a memory leak of 6 bytes, including the terminating null character.

### Validation

The observed output confirms that the structures and their names have distinct addresses.

The program terminates without a visible crash. However, source code analysis reveals a memory leak.

The predicted leak must be verified with Valgrind during the memory tracer task.

## 4. Critical Review of AI-Generated Analysis

### AI tool used

ChatGPT was used to generate preliminary memory maps and explanations of stack frames, pointer aliasing, heap allocations and object lifetimes.

### Identified incomplete explanation

The initial AI-generated memory map for stack_example.c represented the recursive walk_stack() calls but omitted the temporary dump_frame() stack frames.

### Why this was incomplete

The function dump_frame() creates its own local variables:

- local_int
- local_buf
- p_local

These variables have different lifetimes from the marker variable in walk_stack().

Omitting these temporary frames does not provide a complete representation of the program's memory state.

### Correction

The corrected memory map includes the active dump_frame() frame and its local variables.

The source code and execution output were compared to distinguish the lifetime of marker from the lifetime of the variables inside dump_frame().

The observed reuse of identical addresses between entry and exit calls does not mean that the original local objects remained alive.

### Conclusion

AI-generated memory maps must be treated as hypotheses and checked against the source code and actual execution results.

A program that executes without crashing is not necessarily memory-safe.

## 5. References

- Valgrind User Manual: https://valgrind.org/docs/manual/manual.html
- SEI CERT C Coding Standard, MEM30-C — Do not access freed memory: https://cmu-sei.github.io/secure-coding-standards/sei-cert-c-coding-standard/rules/memory-management-mem/mem30-c/
- GCC Warning Options: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
