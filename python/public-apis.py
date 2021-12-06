#!/usr/bin/env python3

import requests
import json

response = requests.get("https://api.publicapis.org/entries")
linked = response.json()

print(json.dumps(linked, indent=4))
