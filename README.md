This project is a C++ application designed to process and analyze a list of produce items from a text file. 
It utilizes a map data structure to store item names and their corresponding quantities, allowing users to interact with the data through a console-based menu. 
The program offers several key features, including searching for a specific item and displaying its quantity, listing all items with their quantities, and generating a histogram to visualize item frequency. 
Upon exiting, the application writes the data to a timestamped output file in .dat format for record-keeping. The code emphasizes modular design, user input handling, and basic data visualization.

What did you do particularly well?
One aspect that was particularly well executed was the modular structure of the code. 
Functions were clearly separated by purpose, including reading input, handling user interactions, and writing output.
This organization made the logic easier to follow and maintain.
Additionally, using a map to store item data allowed for efficient lookups and updates.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
Areas that can be improved include input validation and error handling. For instance, enhancing the management of invalid menu selections or handling file access failures would make the program more robust and user friendly. 
Additionally, replacing `system("CLS")` and `system("pause")` with specific platform alternatives would enhance both portability and security.

Which piece of the code did you find most challenging to write, and how did you overcome this? What tools are you adding to your support network?
A key challenge in this project was updating item quantities in the GroceryItemMap using smart pointers. When an item already existed, I needed to retrieve its quantity, increment it, and then replace the old entry with a new ProduceItem—all while ensuring memory safety. 
This required precise use of `std::unique_ptr` and a solid understanding of ownership semantics. I managed to overcome this challenge by breaking the logic into clear steps, using `std::make_unique` for clean object creation, and relying on compiler warnings along with runtime tests to ensure proper memory management.
During this project, I reached out to a friend who provided valuable guidance and introduced me to resources that greatly improved my problem solving approach. One of the most helpful tools I discovered was cppreference.com, which offers clear explanations of C++ functions and syntax. Additionally, I began using Stack Overflow more actively, where I found practical solutions to issues similar to mine and learned how others tackled common programming challenges. These resources became essential to my success in this course and have strengthened my support network for future projects.

What Skills from this project will be particularly transferable to other projects or course work?
As I continue writing code and deepening my understanding of programming languages, I’ve found that the logic and structure behind them are becoming much clearer. What once felt completely foreign and overwhelming has transformed into something I can read, interpret, and reason through. I’ve gone from knowing virtually nothing to grasping not just what the code does, but why it needs to do it that way. With continued practice, I know my understanding will only grow stronger and that foundation is something I’ll carry forward into future courses and projects.

How did you make this program maintainable, readable, and adaptable? 
To ensure maintainability and readability, the program uses consistent naming conventions, inline comments, and clear function boundaries. Adaptability is supported through reusable components and a logical flow that could easily be extended to handle more complex data formats or additional features.
