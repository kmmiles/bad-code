#!/usr/bin/env pwsh

function MyFunction1 {
  Write-Output "Hello, MyFunction1!"
}

function MyFunction2 {
  Write-Output "Hello, MyFunction2!"
}

function MyFunction1 {
  Write-Output "Hello, MyFunction3!"
}

for($i=1;$i -le 5; $i++) {
  if($i -eq 3) {
    Continue
  }
  Write-Host "i = $i"
}
