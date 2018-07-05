#!/bin/bash
cd `dirname $0`; pwd
git  add *
git commit -m 'auto updated by update.sh'
git push
