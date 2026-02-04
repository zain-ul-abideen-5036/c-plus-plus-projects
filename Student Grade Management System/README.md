# Student Grade Management System  
A C++ console application to manage student grades, calculate overall performance, and provide feedback.  

---  
## Features  
- **Student Data Entry:** Store student names, IDs, and scores (assignments, quizzes, exams).  
- **Automatic Grading:** Calculates overall grade (30% assignments, 20% quizzes, 50% exams).  
- **Letter Grade & Feedback:** Assigns grades (A-F) with customized feedback messages.  
- **Data Persistence:** Saves records to `student_data.txt` for future reference.  
- **Batch Processing:** Supports entry for up to 100 students in one session.  

---  

## Example:
   ```bash
      Enter student name: Maria  
      Enter student ID: 1001  
      Enter assignment score (0-100): 85  
      Enter quiz score (0-100): 90  
      Enter exam score (0-100): 78  

      Student added successfully.  
      Do you want to add another student? (y/n): n  

      <-----Student Results----->  

      Name: Maria  
      ID: 1001  
      Overall Grade: 81.3  
      Letter Grade: B  
      Feedback: Good job, but there is room for improvement.  
  ```
---
