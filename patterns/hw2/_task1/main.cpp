#include <iostream>
#include "decorator.h"

int main() {
   auto text_block = new Paragraph(new ItalicText(new BoldText(new Text())));
   text_block->render("Hello world");
   std::cout << std::endl;
   auto text_block1 = new Reversed( new Text());
   text_block1->render("Hello world");
   std::cout << std::endl;
   auto text_block2 = new Link( new Text());
   text_block2->render("netology.ru", "Hello world");
   return 0;
}