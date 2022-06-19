//import process from 'process';

import { stdin, stdout } from 'process';


interface Position {
  row: number
  col: number
}

const items: number[][] = [
  [1, 2, 3, 4, 5],
  [3, 4, 5, 6, 7],
  [8, 9, 10, 11, 12],
  [13, 14, 15, 16, 17],
  [18, 19, 20, 21, 22],
];

const target_pos: Position = {row: 2, col: 2};
const pos: Position = {row: 0, col: 0};
for (pos.row = 0; pos.row < items.length; pos.row++) {
  for (pos.col = 0; pos.col < items[pos.row].length; pos.col++) {
    if (pos.row === target_pos.row && pos.col === target_pos.col) {
      const val = `*${items[pos.row][pos.col]}`.padStart(5, ' ');
      stdout.write(`${val}`);
    } else {
      const val = `${items[pos.row][pos.col]}`.padStart(5, ' ');
      stdout.write(`${val}`);
    }
  }
  stdout.write("\n");
}
