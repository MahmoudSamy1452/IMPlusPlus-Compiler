const express = require('express');
const { execFileSync } = require('child_process');
const fs = require('fs');
const dotenv = require('dotenv');
const cors = require('cors');
const app = express();

dotenv.config();

app.use(express.json());
app.use(cors());

app.get('/', (req, res) => {
  res.send('Hello World!');
});

app.post('/compile', async (req, res) => {
  const { code } = req.body;
  try {
    fs.writeFileSync('testcase.txt', code, (err) => {
      if (err) throw err;
      console.log('File written successfully!');
    });
  } catch (err) {
    console.error(err);
  }
  try {
    const stdout = execFileSync('cmd', ['/c', process.env.BATPATH]);
    console.log(stdout.toString());

    let quad = fs.readFileSync('Quadruples.txt', 'utf8');
    let symbolTable = fs.readFileSync('symbolTable.txt', 'utf8');
    let errors = fs.readFileSync('errorMessages.txt', 'utf8');

    res.status(200).json({ quad, symbolTable, errors });
  } catch (error) {
    console.error(error);
    res.status(500).send('An error occurred');
  }
})

const port = process.env.PORT || 3000;
app.listen(port, () => console.log(`Server running on port ${port}`));