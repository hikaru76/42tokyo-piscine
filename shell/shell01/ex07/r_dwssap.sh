cat /etc/passwd |awk 'NR%2==0' | sed '/^#/d'| cut -d\: -f1|rev|sort -r|sed -n $FT_LINE1,${FT_LINE2}p| tr '\n' ' ' | sed 's/ /, /g' | sed 's/..$/\./' | tr -d '\n'
