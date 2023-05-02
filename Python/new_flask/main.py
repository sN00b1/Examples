from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    return 'Hello world! <br> href='

@app.route('/index')
def index():
    return 'Its my first project'

if __name__ == '__main__':
    app.run()