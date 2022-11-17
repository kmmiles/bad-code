#!/usr/bin/env python3
"""read template from stdin, substitute values, and write to stdout"""
from string import Template

with open(0, encoding="ascii") as f:
    print(Template(f.read()).substitute({'mytag': 'this new text replaced "$mytag"'}))
