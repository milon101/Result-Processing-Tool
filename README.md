# Result-Processing-Tool
This project is for SUST A Unit Admission Result Processing 

## How It Works

1. To process results we need two types of information. First, we need previous college result information since it has a 30% contribution to the admission result and second, we need the answer to the multiple-choice questions arranged by the university.

2. Due to the lack of access to these data I have decided to generate these first. Teletalk is a government organization that provides all the previous data. In this project, I have created a teletalk.c file to generate these kinds of data.

3. There is an MCQ assessment arranged by the university and every student result sheet reads through an automated system to give a combined OMR data. OMR.c file is used to generate these kinds of data.

4. After data generation a final result sheet is generated that contains all the processed for individuals. 
