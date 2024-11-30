############################################
##
## AWK Program
##
## Created by Reinaldo Moraga (z1864815)
##
## Date Due: 4/22/20
##
############################################

BEGIN {
	# First header is printed
	FS= ":"
	print "Products"
	print "--------"
	print "Product ID\tCategory\t\tDescription\t\t\t\t     Price"
	print "=========================================================================================="
}
	# Product records are displayed
	NR <= 6 {	
		printf("%2d\t\t%-20s\t%-35s\t%10.2f\n", $1, $2, $3, $4)
	}
	NR == 7 {
		print "==========================================================================================\n\nAssociates\n----------\nAssocciate ID\tName\t\t\t\tPosition\n========================================================"
	}

	# Associate records are displayed
	NR >= 8 && NR <= 15 {
		printf("%2d\t\t%-20s\t%16s\n", $1, $2, $3)
	}

	NR == 16 {
		
		print "========================================================\n\nSales\n-----\nTransaction ID\tProduct ID\tQuantity\tDate\t     Associate ID\n========================================================================="
	}
	
	# Sales records are displayed
	NR >= 17 {
		printf("%2d\t\t%d\t\t%d\t\t%-s\t\t%-d\n", $1, $2, $3, $4, $5)
	}
END {
	print "========================================================================="
}

