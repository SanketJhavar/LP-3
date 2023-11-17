// SPDX-License-Identifier: MIT
pragma solidity 0.8;

contract Account{
    uint public balance;
    address public account;

    constructor()
    {
        account = msg.sender;
    }

    function deposit(uint amt_) public {
        balance += amt_;
    }

    function withdraw(uint amt_) public {
        balance -= amt_;
    }

    function get_balance() view public returns (uint){
        return balance;
    }
}
