var gulp = require('gulp');
var sass = require('gulp-sass');

gulp.task('sass', function() {
  var sassOptions = {
    includePaths: ['src/sass/neat'],
    outputStyle: 'expanded'
  }

  return gulp.src('src/sass/**')
    .pipe(sass(sassOptions).on('error', sass.logError))
    .pipe(gulp.dest('dist/css'));
});

gulp.task('default', ['sass'], function() {
  gulp.watch('src/sass/**', ['sass']);
});
