/*
 * L3E6.cpp
 * 
 * Copyright 2015 Willane <willane@willane-ubuntu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
using namespace std;
int main()
{
	int num,cont1,cont2;

	cont1=0;
	cont2=0;
	while(num != 0)
	{
		cout<<"Digite um número: ";
		cin>>num;
		cont1++;
	if((num%2 != 0) && (num>15))
	cont2++; 
	}
	cout<<"Porcentagem dos números ímpares maiores que 15: "<<((cont2*100.0)/cont1)<<"%";	
	return 0;
}

