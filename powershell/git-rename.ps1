param (
    [Parameter(Mandatory = $true)]$repo_name,
    [Parameter(Mandatory = $true)]$project_name,
    [Parameter(Mandatory = $true)]$token
)

function RenameFiles {
    param (
        [string] $dir_path
    )

    Set-Location $dir_path
    
    $match = "MicroserviceName"
    $files = Get-ChildItem $(get-location) -filter *MicroserviceName* -Recurse

    $files |
    Sort-Object -Descending -Property { $_.FullName } |
    Rename-Item -newname { $_.name -replace $match, $project_name } -force

    $files = Get-ChildItem $(get-location) -include *.cs, *.csproj, *.sln -Recurse 

    foreach($file in $files) 
    { 
        ((Get-Content $file.fullname) -creplace $match, $project_name) | set-content $file.fullname 
    }

    Set-Location ..
    Write-Output "Exiting............"
}


#$checkout_branch = "automated-customize-project"
#$repo_link = "abc"
#git clone $repo_link
#Set-Location $repo_name
#git checkout -b $checkout_branch origin/master
#git fetch --all
#Set-Location ..
#RenameFiles $repo_name
#Set-Location $repo_name
#git add -A
#git commit -m ""Customized template project""
#git push -u origin $checkout_branch

## Removes the repo once done ##
Set-Location $repo_name
Remove-Item -Force -Recurse "".git""
Set-Location ..
Remove-Item $repo_name -Recurse
