#!/usr/bin/env pwsh

$InstalledSoftware = new-Object PsObject -property @{
  DisplayName='displayname'
  DisplayVersion='displayversion'
}

$InstalledSoftware.GetValue('DisplayName')

#$(foreach($obj in $InstalledSoftware) {
#  write-host $obj.GetValue('DisplayName') -NoNewline
#  write-host " - " -NoNewline
#  write-host $obj.GetValue('DisplayVersion')
#}) | Out-File -Force -FilePath "out.txt"
