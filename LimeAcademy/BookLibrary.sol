// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

import "./Ownable.sol";

contract Library is Ownable {
    string internal lib_name;

    struct Book {
        string isbn;
        string title;
        string author;
        uint availableCopies;
    }

    struct Register{
        mapping(string => address[]) bookToAddresses;  //keep the array of every person that got a given book.
        mapping(bytes32 => bool) isBorrowedByUser;     //mapping to prevent many copies borrow.
    }

    mapping(string => Book) internal Books;     //hash table of books for fast search, addition and deletion.
    string[] private registeredBooks;          //array of isbn's for iterative operations.
    uint private registeredBooksCount;          //keep all registered books count to prevent iterating if needed.
    Register private registerBook;
    
    //Events for further usage
    event AddedBook(string memory _isbn, uint _numberOfCopies);
    event BorrowedBook(address _borrowedBy, string memory _isbn);
    event ReturnedBook(address _returnedFrom, string memory _isbn);

    constructor(string memory _libraryName) onlyOwner(){
        lib_name = _libraryName;
        registeredBooksCount = 0;
    }

    function wasBookRegistered(string memory _isbn) internal view returns(bool) {
        bytes memory tmp = bytes(Books[_isbn].title);
        if (tmp.length == 0) {
           return false;
        } 

        return true;
    }

    function addBook(string memory _isbn, string memory _title, string memory _author, uint _numberOfCopies) public onlyOwner() {
        //There is no reason to add book if you don't have it
        require(_numberOfCopies > 0);
        Book storage newBook = Books[_isbn];

        emit AddedBook(_isbn, _numberOfCopies);
        registeredBooksCount += _numberOfCopies;

        //If the book was already registered we should add copies
        if (wasBookRegistered(_isbn)) {
            newBook.availableCopies+= _numberOfCopies;
            return;
        }

        newBook.isbn = _isbn;
        newBook.title = _title;
        newBook.author = _author;
        newBook.availableCopies = _numberOfCopies;

        registeredBooks.push(_isbn);
    } 

    function getRegisteredBooksCount() internal view returns(uint) {
        return registeredBooksCount;
    }

    function getAllAvailableBooks() public view returns(string[] memory) {
        uint books = registeredBooks.length;
        string[] memory available = new string[](books);
        Book memory currentBook;
        
        //Iterate through books and pushe them into string arr.
        for (uint i = 0; i < books; i++) {
            currentBook = Books[registeredBooks[i]];
            
            if (currentBook.availableCopies > 0) {
                available[i] = string(abi.encodePacked("ISBN: ",currentBook.isbn," TITLE: ", currentBook.title, " AUTHOR: ", currentBook.author));
            }
        }

        return available;
    } 

    
}