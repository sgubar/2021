int main(void)
{
	//int averageNum;
	IntList* list = NULL;
	list = createIntList();
	for (int i = 0; i != 10; i++)	//Creating list with 10 elements with random values
	{
		addIntValueToIntList(list, rand() % 100 + 1);
	}

	printf("You have generated a list with 10 elements with rand values:\n");
	printIntList(list);

	int average = countAverageFromList(list);
	printf("The average number of your list is: %d\n", average);
	deleteLessIndexFromList(list, average);
	printf("You have deleted the first element that is less than average:\n");
	printIntList(list);
	deleteIntList(list);
}
