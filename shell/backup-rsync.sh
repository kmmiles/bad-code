#!/bin/bash

function compress() {
    # package the result into a gzip file for easy distribution
    tar zvcf "backup-$BACKUPTIME.tar.gz" -C "$DEST" "$USER"
}

# check if user gives a location to backup to
if [ ! "$1" ]; then
    echo "Directory not given, defaulting to '/HDD/backups/HOMEDIR-CURRENT-BACKUP'."
    BACKDIR=/HDD/backups/HOMEDIR-CURRENT-BACKUP
else
    BACKDIR=$1
fi

# set some vars
BACKUPTIME=$(date +%b-%d-%y)
DEST=$BACKDIR
SRC=/home/$USER
VMS='VirtualBox VMs'

# make destination dir and cd into it
mkdir -p "$DEST" && cd "$DEST"

# copy source to dest and exclude some stuff that i dont need
rsync -av --progress "$SRC" "$DEST" --exclude .local/share/Trash --exclude .audacity-data --exclude .gnome2 --exclude .gnome2_private --exclude .nuget --exclude Projects --exclude .pki --exclude .cache --exclude .minetest --exclude .openshot_qt --exclude "$VMS" --exclude .config/discord/Cache --exclude *.iso && echo "Backup successful." || echo "Backup failed!"

clear
echo "Compress into a tar? (Y/n)"
read -p "Enter input: " t
taryn="${t,,}"

if [ "$taryn" == "y" ]; then
    compress
else
    true
fi
