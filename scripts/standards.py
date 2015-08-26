#! /usr/bin/env python3
# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

_groups = (
    'assignment completion',
    'history and culture',
    'design',
    'review',
    'general programming',
    'object-oriented programming',
)

_multipliers = {
          'assignment completion': 0.05,
            'history and culture': 0.05,
                         'design': 0.15,
                         'review': 0.15,
            'general programming': 0.30,
    'object-oriented programming': 0.30,
}

_standards = {
    'assignment completion': (
        'assignment completion',
    ),

    'history and culture': (
        'history and culture :: general knowledge',
    ),

    'design': (
        'design :: general knowledge',
        'debugging and testing correctness',
        'pseudocode',
        'documentation',
        'consistency of style',
    ),

    'review': (
        'review :: general knowledge',
        'visual studio',
        'data types and representation',
        'operators',
        'control flow',
        'arrays',
        'functions',
        'file I/O',
    ),

    'general programming': (
        'general programming :: general knowledge',
        'recursion',
        'searching, sorting, and algorithm analysis',
        'type declarations',
        'pointers and references',
        'memory management and dynamic memory',
        'templates',
        'standard library',
        'parallel arrays',
    ),

    'object-oriented programming': (
        'object-oriented programming :: general knowledge',
        'member functions',
        'interfaces',
        'inheritance',
        'polymorphism',
        'exceptions',
    ),
}

# -----------------------------------------------------------------------------

groups = {
    g: { 'multiplier': _multipliers[g], 'standards': _standards[g] }
    for g in _groups
}

standards = {
    s: { 'group': g, 'multiplier': _multipliers[g] / len(_standards[g]) }
    for g in _groups
    for s in _standards[g]
}

# -----------------------------------------------------------------------------

if __name__ == '__main__':
    for g in _groups:
        print('- ' + g + ' (' + str(_multipliers[g]*100) + '%)')
        for s in _standards[g]:
            print('    - ' + s)
        print()

