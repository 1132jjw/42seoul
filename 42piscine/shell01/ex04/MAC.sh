ifconfig -a | grep ether | grep -v ethernet | sed "s/ether//" | sed 's/[[:blank:]]//g'
