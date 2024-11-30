#!/bin/bash

############################################
##
## Automobile Database Shell Program
##
## Created by Reinaldo Moraga (z1864815)
##
## Date Due: 4/10/20
##
############################################

# New function creates a new datatbase with a label

new () {
	echo "$2" > $1
	echo -e "New database created\n"
}

# Add function adds a new record to an existing
# database

add () {
	echo "$2, $3, $4, $5" >> $1
	echo -e "Successfully added a record to the database\n"
}

# Show function displays the database based on
# what the user requests

show () {
	if [ "$2" = 'all' ]
	then
		cat "$1"
		echo " "
	elif [ "$2" = 'single' ]
	then
		let count="$3"
		let count++

		sed -n -e "$count"p "$1"
		echo " "
	else
		let num1="$3"
		let num1++
		let num2="$4"
		let num2++

		sed -n -e "$num1","$num2"p "$1"
		echo " "
	fi
}

# Delete function deletes records from a
# databse based on what the user requests

delete () {
	if [ "$2" = 'all' ]
	then
		sed -i '1!d' "$1"
		echo -e "All records deleted\n"	
	elif [ "$2" = 'single' ]
	then
		let number="$3"
		let number++
		
		sed -i "$number"'d' "$1"
		echo -e "1 record deleted\n"
	else
		let snum="$3"
		let snum++
		let enum="$4"
		let enum++
		let total="$4"-"$3"+1

		sed -i "$snum","$enum"'d' "$1"
		echo -e "$total records deleted\n"
	fi
}

# Count function displays the line count for
# the specified database

count () {
	wc -l "$1" | awk '{ print $1 }'
	echo " "
}

# If no arguments are detected, the program goes into interactive mode

if [ $# -eq 0 ]
then
	action=blank

	# Program will continue prompting until user types in q

	while [ $action != 'q' ]
	do
		read -p "Choose what you would like to do! (new, add, show, count, delete or q to quit) " action
		echo " "
		
		# Based on what action was chosen, the case will follow

		case "$action" in
			
			# Asks user for filename and label and calls new function

			new|New|NEW) 
				read -p "What is the filename? " filename
				read -p "What is the label? " label
				new "$filename" "$label" ;;

			# Asks user for a name of a file to add to, program checks if file is valid, and if valid
			# the program asks for make, model, year, and color of the car

			add|Add|ADD)
				read -p "What file would you like to add to? " aname

				if [[ ! -f "$aname" || ! -r "$aname" || ! -w "$aname" ]]
				then
					echo -e "*** ERROR: Invalid file or filename ***\n"
				else
					read -p "What is the make of the vehicle? " make
					read -p "What is the model of the vehicle? " model
					read -p "What is the year of the vehicle? " year
					read -p "What is the color of the vehicle? " color
					add "$aname" "$make" "$model" "$year" "$color"
				fi ;;

			# Asks user for a name of a file to display, program checks if file is valid, and if valid
			# the program asks what they would like to show. Different display options are given
			# depending on their answer

			show|Show|SHOW)
				read -p "What file would you like to see? " sname

				if [[ ! -f "$sname" || ! -r "$sname" || ! -w "$sname" ]]
				then
					echo -e "*** ERROR: Invalid file or filename ***\n"
				else
					read -p "What would you like to show? (all, single, or range) " show
					
					case "$show" in
						all|All|ALL)
							echo " "
							show "$sname" "$show" ;;

						single|Single|SINGLE)
							read -p "What record number would you like to see? " number
							echo " "
							show "$sname" "$show" "$number" ;;

						range|Range|RANGE)
							read -p "What record number would you like to start with? " rstart
							read -p "What record number would you like to end with? " rend
							echo " "
							show "$sname" "$show" "$rstart" "$rend" ;;
					esac
				fi ;;
			
			# Asks user for the name of a file they would like to delete, program checks if file is valid, and if
			# valid, the program asks what they would like to delete. Depending on user's answers, certain records
			# are deleted

			delete|Delete|DELETE)
				read -p "What file would you like to delete? " dname

				if [[ ! -f "$dname" || ! -r "$dname" || ! -w "$dname" ]]
				then
					echo -e "*** ERROR: Invalid file or filename ***\n"
				else
					read -p "What would you like to delete from the file? (all, single, or range) " del

					case "$del" in
						all|All|ALL)
							delete "$dname" "$del" ;;

						single|Single|SINGLE)
							read -p "What record number would you like to delete? " line
							delete "$dname" "$del" "$line" ;;

						range|Range|RANGE)
							read -p "What record number would you like to start with to delete? " rs
							read -p "What record number would you like to end with to delete? " re
							delete "$dname" "$del" "$rs" "$re" ;;
					esac
				fi ;;
			
			# Asks uder for the name of a file they would like to count, program checks if file is valid, and if so
			# the program displays the line number of the database

			count|Count|COUNT)
				read -p "What file would you like to count? " cname

				if [[ ! -f "$cname" || ! -r "$cname" || ! -w "$cname" ]]
				then
					echo -e "*** ERROR: Invalid file or filename ***\n"
				else
					count "$cname"
				fi ;;
		esac	
	done	
else
	# If arguments are detected, the program checks to see what commands the user has put
	# Each if loop goes through and checks what command is chosen and how many parameters are given
	# Specific error displays are also given

	if [ $# -eq 1 ]
	then
		echo "*** ERROR: Specify command"
		exit 1
	fi

	if [ "$2" = 'new' ]
	then
		if [ $# -eq 3 ]
		then
			new "$1" "$3"
		else
			param="Untitled database"
			new "$1" "$param"
		fi
	fi

	if [ "$2" = 'add' ]
	then
		if [ $# -eq 6 ]
		then
			add "$1" "$3" "$4" "$5" "$6"
		else
			echo "*** ERROR: Not enough arguments ***"
			exit 1
		fi
	fi

	if [ "$2" = 'show' ]
	then
		if [ $# -eq 3 ]
		then
			show "$1" "$3"
		elif [ $# -eq 4 ]
		then
			show "$1" "$3" "$4"
		else
			show "$1" "$3" "$4" "$5"
		fi
	fi

	if [ "$2" = 'delete' ]
	then
		if [ $# -eq 3 ]
		then
			delete "$1" "$3"
		elif [ $# -eq 4 ]
		then
			delete "$1" "$3" "$4"
		else
			delete "$1" "$3" "$4" "$5"
		fi
	fi

	if [ "$2" = 'count' ]
	then
		if [ $# -eq 1 ]
		then
			echo "*** ERROR: Didn't specify filename ***"
			exit 1
		elif [ $# -eq 2 ]
		then
			count "$1"
		else
			echo "*** ERROR: Too many arguments ***"
			exit 1
		fi
	fi
fi

